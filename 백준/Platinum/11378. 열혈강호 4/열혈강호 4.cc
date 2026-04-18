#include <bits/stdc++.h>
using namespace std;
using vi = vector<int>;
#define FIO                                                                    \
  ios_base::sync_with_stdio(0);                                                \
  cin.tie(0);                                                                  \
  cout.tie(0);
#define all(x) x.begin(), x.end()
const int MAXN = 1e4 + 4;
bool match[MAXN];  // 매칭 상태
int matched[MAXN]; // 매칭된 상대
vi edges[MAXN];
bool CanDoing[MAXN];
int N, M, K, Cando;

bool dfs(int node) {
  for (auto &edge : edges[node]) {
    if (match[edge])
      continue;
    match[edge] = true;
    if (!matched[edge] || dfs(matched[edge])) {
      matched[edge] = node;
      return 1;
    }
  }
  return 0;
}
int solveA() {
  int ans = 0;
  for (int i = 1; i <= N; i++) {
    fill(match, match + MAXN, 0);
    if (dfs(i)) {
      ans++;
    }
  }
  return min(ans + K, Cando);
}
void init() {
  cin >> N >> M >> K;
  for (int i = 1; i <= N; i++) {
    int tmp;
    cin >> tmp;
    while (tmp--) {
      int c;
      cin >> c;
      if (!CanDoing[c]) {
        CanDoing[c] = 1;
        Cando++;
      }
      edges[i].push_back(c);
    }
  }
}
int solveB() {
  int ans = 0;
  fill_n(matched, MAXN, 0);
  for (int i = 1; i <= N; i++) {
    fill(match, match + MAXN, 0);
    if (dfs(i)) {
      ans++;
    }
  }
  int k = 0;
  for (int i = 1; i <= N && k < K; i++) {
    while (k < K && dfs(i)) {
      fill(match, match + MAXN, 0);
      ans++, k++;
    }
  }
  return ans;
}
int main() {
  FIO;
  init();
  cout << solveB() << endl;
  return 0;
}
