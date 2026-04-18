#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define endl "\n"
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
  // freopen("output.txt", "w", stdout);
#endif
}
int N;
int arr[1001];
void rev(int s, int e)
{
  int siz = e - s + 1;
  for (int i = 0; i < siz / 2; i++)
  {
    swap(arr[s + i], arr[e - i]);
  }
}
bool grass[1001][1001];
int n, m, q;
int cnt = 0;
int main()
{
  init();
  cin >> n >> m >> q;
  while (q--)
  {
    int a;
    cin >> a;
    if (a == 1)
    {
      int dy, dx, y, x;
      cin >> dy >> dx >> y >> x;
      while (1 <= x && x <= m && 1 <= y && y <= n)
      {
        if (!grass[y][x])
        {
          grass[y][x] = 1;
          cnt++;
        }
        else
          break;
        x += dx, y += dy;
      }
    }
    else if (a == 2)
    {
      int y, x;
      cin >> y >> x;
      cout << grass[y][x] << endl;
    }
    else
    {
      cout << n * m - cnt << endl;
    }
  }
  return 0;
}
