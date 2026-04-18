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

int N, M, K, S, D;
vector<pair<int, int>> graph[1001];
int tax[30001];

int dp[1001][1001]; // dp[사용도로수][도착값]
int main()
{
  init();
  cin >> N >> M >> K >> S >> D;
  for (int i = 0; i < M; i++)
  {
    int a, b, w;
    cin >> a >> b >> w;
    graph[a].push_back({b, w});
    graph[b].push_back({a, w});
  }
  for (int i = 0; i < K; i++)
    cin >> tax[i];

  for (int i = 0; i <= N; i++)
    for (int j = 0; j <= N; j++)
      dp[i][j] = INT_MAX;
  priority_queue<array<int, 3>>
      pq; // 지금까지의 값,이동한 도로의 갯수, 경유지
  pq.push({0, 0, S});
  int cc = 0;
  while (!pq.empty())
  {
    auto [minTra, cnt, end] = pq.top();
    pq.pop();
    cc++;
    if (dp[cnt][end] < -minTra)
      continue;
    for (int i = cnt; i <= N; i++)
      dp[i][end] = min(dp[i][end], -minTra);
    for (auto &[loc, wei] : graph[end])
    {
      if (dp[cnt + 1][loc] > dp[cnt][end] + wei)
      {
        dp[cnt + 1][loc] = dp[cnt][end] + wei;
        pq.push({-dp[cnt + 1][loc], cnt + 1, loc});
      }
    }
  }
  int sumTax = 0;
  for (int i = 0; i <= K; i++)
  {
    int ans = INT_MAX;
    for (int j = 0; j <= N; j++)
    {
      if (dp[j][D] != INT_MAX)
        ans = min(ans, dp[j][D] + sumTax * j);
    }
    cout << ans << endl;
    sumTax += tax[i];
  }
  return 0;
}
