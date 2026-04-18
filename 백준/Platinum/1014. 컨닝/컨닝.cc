#include <bits/stdc++.h>
using namespace std;
using ll = long long;
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

int C, N, M;
vector<string> classroom;
vector<int> valid_masks;
int dp[11][1 << 10];

// 상대 자리와 같은 행에서 두 학생이 없는지 판단
bool isValidRow(int mask) { return !(mask & (mask << 1)); }

// 두 상황 각각이 동존한 층에 있을 경우 범위 처리
bool isCompatible(int prev, int curr) {
  return !(curr & (prev << 1)) && !(curr & (prev >> 1));
}

int countBits(int mask) {
  int cnt = 0;
  while (mask) {
    cnt += (mask & 1);
    mask >>= 1;
  }
  return cnt;
}

int solve() {
  fill(&dp[0][0], &dp[0][0] + sizeof(dp) / sizeof(int), -1);
  vector<vector<int>> row_masks(N);
  //가능한 마스크 조합 다 찾기
  for (int r = 0; r < N; ++r) {
    for (int mask = 0; mask < (1 << M); ++mask) {
      bool ok = true;
      for (int c = 0; c < M; ++c) {
        if ((mask & (1 << c)) && classroom[r][c] == 'x')
          ok = false;
      }
      if (ok && isValidRow(mask)) {
        row_masks[r].push_back(mask);
      }
    }
  }

  for (int mask : row_masks[0]) {
    dp[0][mask] = countBits(mask);
  }

  for (int r = 1; r < N; ++r) {
    for (int curr : row_masks[r]) {
      for (int prev : row_masks[r - 1]) {
        if (isCompatible(prev, curr) && dp[r - 1][prev] != -1) {
          dp[r][curr] = max(dp[r][curr], dp[r - 1][prev] + countBits(curr));
        }
      }
    }
  }

  int ans = 0;
  for (int mask : row_masks[N - 1]) {
    ans = max(ans, dp[N - 1][mask]);
  }
  return ans;
}

int main() {
  init();

  cin >> C;
  while (C--) {
    cin >> N >> M;
    classroom.clear();
    classroom.resize(N);
    for (int i = 0; i < N; ++i) {
      cin >> classroom[i];
    }
    cout << solve() << '\n';
  }

  return 0;
}
