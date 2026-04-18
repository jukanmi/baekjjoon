#include <bits/stdc++.h>
using namespace std;
using vi = vector<int>;
using vii = vector<pair<int, int>>;
using ii = pair<int, int>;
#define endl "\n"
#define all(x) x.begin(), x.end()
const int MAXN = 1e3 + 4;
const int INF = 987654321;
int n, m;
vi startToEnd[MAXN];
/** dp[i][j] = i번째날을 포함하지않는 가장 긴 여행을 가지않는 구간 = j라 할때
 * i번째 날을 포함하는 여행을 안하는 구간의 길이
 */
int dp[MAXN][MAXN];
int solve() {
  for (int i = 0; i <= n; i++)
    fill_n(dp[i], n + 1, INF);
  dp[0][0] = 0;
  for (int i = 0; i <= n; i++) {
    for (int j = 0; j <= n; j++) {
      if (dp[i][j] == INF)
        continue;
      dp[i + 1][j] = min(dp[i][j] + 1, dp[i + 1][j]);
      for (int k : startToEnd[i]) {
        dp[k][max(dp[i][j],j)] = 0;
      }
    }
  }
  int ans = INF;
  for (int i = 0; i <= n; i++){
    ans = min(ans, max(dp[n][i], i));
    //cout << i << ":" << dp[n][i]  << endl;
  }
  return ans;
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
#ifndef BOJ
  freopen("input.txt", "r", stdin);
#endif
  cin >> n >> m;
  for (int i = 0; i < m; i++) {
    int a, b;
    cin >> a >> b;
    startToEnd[a - 1].push_back(b);
  }
  cout << solve() << endl;
  return 0;
}
