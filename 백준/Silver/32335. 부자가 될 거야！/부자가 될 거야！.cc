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

int main()
{
  init();
  int N, M;
  cin >> N >> M;
  vector<int> a(N);
  char c;
  for (int i = 0; i < N; i++)
  {
    cin >> c;
    a[i] = c - '0';
  }
  for (int i = 0; i < N - 1; i++)
  {
    if (a[i] == 0)
      continue;
    if (a[i] + M >= 10)
    {
      int cnt = 10 - a[i];
      M -= cnt;
      a[i] = 0;
    }
  }
  a[N - 1] = (a[N - 1] + M) % 10;
  for (auto &i : a)
    cout << i;
  return 0;
}
