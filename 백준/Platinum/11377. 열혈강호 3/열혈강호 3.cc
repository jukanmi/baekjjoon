#include <bits/stdc++.h>
using namespace std;
using vi = vector<int>;
#define FIO                                                                    \
  ios_base::sync_with_stdio(0);                                                \
  cin.tie(0);                                                                  \
  cout.tie(0);
#define all(x) x.begin(), x.end()
const int MAXN = 1e4 + 4;
bool match[MAXN];
int matched[MAXN];
int N, M, K;

bool dfs(int node, vector<vi> &edges) {
  for (auto &edge : edges[node]) {
    if (match[edge])
      continue;
    match[edge] = 1;
    if (!matched[edge] || dfs(matched[edge], edges)) {
      matched[edge] = node;
      return 1;
    }
  }
  return 0;
}

int main() {
  FIO;
  cin >> N >> M >> K;
  vector<vi> edges(N + 1, vi());
  for (int i = 1; i <= N; i++) {
    int tmp;
    cin >> tmp;
    while (tmp--) {
      int c;
      cin >> c;
      edges[i].push_back(c);
    }
  }
  int ans = 0;
  for (int i = 1; i <= N; i++) {
    fill_n(match, MAXN, 0);
    if (dfs(i, edges)) {
      ans++;
    }
  }

  for (int i = 1; i <= N && K>0; i++){
    fill_n(match,MAXN,0);
    if (dfs(i, edges)) {
      ans++;
      K--;
    }
  }
  cout << ans;
  return 0;
}
