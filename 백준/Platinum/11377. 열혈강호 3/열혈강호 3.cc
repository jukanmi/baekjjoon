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
bool worked[MAXN]; // 해당 상대가 이미 매칭되었는지
vi edges[MAXN];
int N, M, K;

bool dfs(int node) {
  if (match[node])
    return 0;
  match[node] = 1;
  for (auto &edge : edges[node]) {
    if (!matched[edge] || dfs(matched[edge])) {
      matched[edge] = node;
      return 1;
    }
  }
  return 0;
}

int main() {
  FIO;
  //freopen("input.txt", "r", stdin);
  cin >> N >> M >> K;
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
    fill(match, match + MAXN, 0);
    if (dfs(i)) {
      ans++;
    }
  }
  for (int i = 1; i <= N && K > 0; i++) {
    fill(match, match + MAXN, 0);
    if (dfs(i)) {
      ans++, K--;
    }
  }
  cout << ans;
  return 0;
}
