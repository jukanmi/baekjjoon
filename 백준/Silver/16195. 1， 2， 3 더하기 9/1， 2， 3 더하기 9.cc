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
// dp[i][j] = 합해서 i가 되는 경우의수, j개의 수를 사용
ll dp[1001][1001];
ll solve(int n, int m)
{
  memset(dp, 0, sizeof(dp));
  dp[0][0] = 1;
  for (int i = 1; i <= n; i++)
  {
    for (int j = 1; j <= m; j++)
    {
      dp[i][j] = dp[i - 1][j - 1];
      if (i - 2 >= 0)
        dp[i][j] += dp[i - 2][j - 1];
      if (i - 3 >= 0)
        dp[i][j] += dp[i - 3][j - 1];
      dp[i][j] %= 1000000009;
    }
  }
  int ans=0;
  for (int i = 1; i <= m; i++)
    ans=(ans+dp[n][i])%1000000009;
  return ans;
}
int main()
{
  init();
  int t;
  cin >> t;
  while (t--)
  {
    int n, m;
    cin >> n >> m;
    cout << solve(n, m) << endl;
  }

  return 0;
}
