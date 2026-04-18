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
  // freopen("out.txt", "w", stdout);
#endif
}

// 사진 올라온 타이밍
int up[101];
int min_stu(int n, map<int, int> &m)
{
  int idx = 0;
  int mm = INF;
  for (auto &p : m)
  {
    if (mm > p.second || (mm == p.second && up[idx] > up[p.first]))
    {
      idx = p.first, mm = p.second;
    }
  }
  return idx;
}
int main()
{
  init();
  int n;
  cin >> n;
  // m[학생] = 추천수
  map<int, int> m;
  int c;
  int upload = 0;
  cin >> c;
  while (c--)
  {
    int x;
    cin >> x;
    if (m.find(x) != m.end())
      m[x]++;
    else if (m.size() < n)
    {
      m[x] = 1;
      up[x] = upload++;
    }
    else
    {
      int idx = min_stu(n, m);
      m.erase(idx);
      m[x] = 1;
      up[x] = upload++;
    }

  }
  for (auto &p : m)
    cout << p.first << " ";
  return 0;
}
