#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define endl "\n"

const ll INF = 2147483647;
void init()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0); /*
   cout.precision(9);
   cout<<fixed;
   /**/
#ifndef BOJ
  freopen("input.txt", "r", stdin);
#endif
};
struct State
{
  int h1, h2, h3, count;
};

bool visited[61][61][61];
int dmg[6][3] = {
    {9, 3, 1}, {9, 1, 3}, {3, 9, 1}, {3, 1, 9}, {1, 9, 3}, {1, 3, 9}};

int main()
{
  init();
  int n;
  cin >> n;
  vector<int> scv(3, 0);
  for (int i = 0; i < n; i++)
    cin >> scv[i];

  queue<State> q;
  q.push({scv[0], scv[1], scv[2], 0});
  visited[scv[0]][scv[1]][scv[2]] = 1;

  while (!q.empty())
  {
    State cur = q.front();
    q.pop();

    if (cur.h1 == 0 && cur.h2 == 0 && cur.h3 == 0)
    {
      cout << cur.count << endl;
      return 0;
    }

    for (int i = 0; i < 6; i++)
    {
      int nh1 = max(0, cur.h1 - dmg[i][0]);
      int nh2 = max(0, cur.h2 - dmg[i][1]);
      int nh3 = max(0, cur.h3 - dmg[i][2]);

      if (!visited[nh1][nh2][nh3])
      {
        visited[nh1][nh2][nh3] = 1;
        q.push({nh1, nh2, nh3, cur.count + 1});
      }
    }
  }
  return 0;
}