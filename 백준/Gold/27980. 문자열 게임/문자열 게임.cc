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
};
int N, M;
int main()
{
  init();
  cin >> N >> M;
  string a, b;
  cin >> a >> b;

  vector<vector<int>> dp(M + 1, vector<int>(N + 1, 0));

  for (int i = 0; i < M; i++)
  {
    for (int j = 0; j < N; j++)
    {
      if (j != 0)
        dp[i + 1][j - 1] = max(dp[i + 1][j - 1], dp[i][j] + (b[i] == a[j]));
      if (j != -1)
        dp[i + 1][j + 1] = max(dp[i + 1][j + 1], dp[i][j] + (b[i] == a[j]));
    }
  }

  int result = 0;
  for (int j = 0; j < N; ++j)
    result = max(result, dp[M][j]);

  cout << result << endl;
  return 0;
}