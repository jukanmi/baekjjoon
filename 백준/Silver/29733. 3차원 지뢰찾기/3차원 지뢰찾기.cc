#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define endl "\n"

const int INF = 987654321;
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
}
int r, c, h;
int cu[101][101][101];
int main()
{
  init();
  cin >> r >> c >> h;
  for (int i = 0; i < h; i++)
    for (int j = 0; j < r; j++)
      for (int k = 0; k < c; k++)
      {
        char a;
        cin >> a;
        if (a == '*')
          cu[i][j][k] = -1;
      }
  vector<tuple<int, int, int>> v;
  for (int i = -1; i <= 1; i++)
    for (int j = -1; j <= 1; j++)
      for (int k = -1; k <= 1; k++)
      {
        if (!i && !j && !k)
          continue;
        v.push_back({i, j, k});
      }
  for (int i = 0; i < h; i++)
    for (int j = 0; j < r; j++)
      for (int k = 0; k < c; k++)
      {
        if (cu[i][j][k] == -1)
          continue;
        for (auto &[di, dj, dk] : v)
        {
          int ni = i + di;
          int nj = j + dj;
          int nk = k + dk;
          if (ni < 0 || ni >= h || nj < 0 || nj >= r || nk < 0 || nk >= c)
            continue;
          if (cu[ni][nj][nk] == -1)
            cu[i][j][k]++;
        }
      }
  for (int i = 0; i < h; i++)
    for (int j = 0; j < r; j++)
    {
      for (int k = 0; k < c; k++)
      {
        if (cu[i][j][k] == -1)
          cout << '*';
        else
          cout << cu[i][j][k]%10;
      }
      cout << endl;
    }
  return 0;
}
