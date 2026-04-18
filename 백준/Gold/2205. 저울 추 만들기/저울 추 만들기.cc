#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define endl "\n"
void init()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
#ifndef BOJ
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
#endif
}
int ans[10001];
int ansCompose(int N)
{
  if (N <= 2)
  {
    return 0;
  }
  int k = 2;
  while (k * 2 <= N)
    k <<= 1;
  int start = 2 * k - N;
  int s = start;
  while (s <= N)
  {
    ans[s] = N - s + start;
    s++;
  }
  return ansCompose(start - 1);
}
int main()
{
  init();
  int N;
  cin >> N;
  ans[1] = 1,ans[2] = 2;
  ansCompose(N);
  for (int i = 1; i <= N; i++)
    cout << ans[i] << endl;
  return 0;
}
