#include <iostream>
#include <vector>
#include <array>
#include <algorithm>
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
int arr[501][501];
int ans[501][501];
pair<int, int> dir[4] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
int main() {
  init();
  int n;
  cin >> n;
  vector<array<int,3>> v;
  for (int i=0;i<n;i++) {
    for (int j=0;j<n;j++) {
      cin >> arr[i][j];
      v.push_back({-arr[i][j],i,j});
    }
  }
  sort(v.begin(), v.end());
  for (auto& [val, i, j] : v) {
    for (auto& [di, dj] : dir) {
      int ni = i + di, nj = j + dj;
      if (ni < 0 || ni >= n || nj < 0 || nj >= n) continue;
      if (arr[ni][nj] >= arr[i][j]) continue;
      ans[ni][nj] = max(ans[i][j]+1, ans[ni][nj]);
    }
  }
  int max_val = 0;
  for (int i=0;i<n;i++) {
    for (int j=0;j<n;j++) {
      max_val = max(max_val, ans[i][j]);
    }
  }
  cout << max_val+1 << '\n';
}
