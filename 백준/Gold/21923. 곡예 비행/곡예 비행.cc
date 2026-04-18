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
  int N, M;
  cin >> N >> M;

  vector<vector<int>> grid(N, vector<int>(M));
  for (int i = 0; i < N; i++)
    for (int j = 0; j < M; j++)
      cin >> grid[i][j];

  const int MIN = -1e9;

  // 상승 비행 DP
  vector<vector<int>> dp_up(N, vector<int>(M, MIN));
  dp_up[N - 1][0] = grid[N - 1][0];

  for (int y = N - 1; y >= 0; y--) {
    for (int x = 0; x < M; x++) {
      if (y + 1 < N)
        dp_up[y][x] = max(dp_up[y][x], dp_up[y + 1][x] + grid[y][x]);
      if (x - 1 >= 0)
        dp_up[y][x] = max(dp_up[y][x], dp_up[y][x - 1] + grid[y][x]);
    }
  }

  // 하강 비행 DP
  vector<vector<int>> dp_down(N, vector<int>(M, MIN));
  dp_down[N - 1][M - 1] = grid[N - 1][M - 1];

  for (int y = N - 1; y >= 0; y--) {
    for (int x = M - 1; x >= 0; x--) {
      if (y + 1 < N)
        dp_down[y][x] = max(dp_down[y][x], dp_down[y + 1][x] + grid[y][x]);
      if (x + 1 < M)
        dp_down[y][x] = max(dp_down[y][x], dp_down[y][x + 1] + grid[y][x]);
    }
  }

  // 최대 점수 계산
  int max_score = MIN;
  for (int y = 0; y < N; y++) {
    for (int x = 0; x < M; x++) {
      int total = dp_up[y][x] + dp_down[y][x];
      max_score = max(max_score, total);
    }
  }

  cout << max_score << endl;
  return 0;
}
