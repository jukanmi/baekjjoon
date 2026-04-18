#include <bits/stdc++.h>
using namespace std;
using ld = long double;
using ll = long long;
using vi = vector<int>;
using vvi = vector<vi>;
using ii = pair<int, int>;
using vii = vector<ii>;
using ll = long long;
using pll = pair<ll, ll>;
const int INF = 1e9;
int n, m;
vector<pair<int, int>> adj[251];

int dist[251][251];

void bfs(int start) {
  deque<int> dq;
  vector<int> d(n + 1, INF);
  d[start] = 0;
  dq.push_back(start);

  while (!dq.empty()) {
    int u = dq.front();
    dq.pop_front();
    for (auto& [v, cost] : adj[u]) {
      if (d[v] > d[u] + cost) {
        d[v] = d[u] + cost;
        if (cost == 0)
          dq.push_front(v);
        else
          dq.push_back(v);
      }
    }
  }

  for (int i = 1; i <= n; ++i)
    dist[start][i] = d[i];
}
void init() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cout << fixed;
  cout.precision(1);
#ifndef BOJ
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
#endif
}

int main() {
  init();

  int u, v, b;
  cin >> n >> m;
  for (int i = 0; i < m; ++i) {
      cin >> u >> v >> b;
      if (b == 0) {
          adj[u].push_back({v, 0});
          adj[v].push_back({u, 1});
      } else {
          adj[u].push_back({v, 0});
          adj[v].push_back({u, 0});
      }
  }

  for (int i = 1; i <= n; ++i)
      bfs(i);

  int k;
  cin >> k;
  while (k--) {
      int s, e;
      cin >> s >> e;
      cout << dist[s][e] << '\n';
  }

  return 0;
}
