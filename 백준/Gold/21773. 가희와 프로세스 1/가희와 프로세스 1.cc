
#include <bits/stdc++.h>
using namespace std;
using vi = vector<int>;
#define endl "\n"
#define FIO                                                                    \
  ios_base::sync_with_stdio(0);                                                \
  cin.tie(0);                                                                  \
  cout.tie(0);
#define all(x) x.begin(), x.end()
const int MAXN = 1e5 + 4;
int N, T;
priority_queue<array<int, 3>> process;
void init() {
  cin >> T >> N;
  for (int i = 0; i < N; i++) {
    int a, b, c;
    cin >> a >> b >> c;
    process.push({c, -a, b});
  }
}
void solve() {
  while (T--) {
    auto [c, a, b] = process.top();
    process.pop();
    cout << -a << endl;
    if (b > 1) {
      process.push({c - 1, a, b - 1});
    }
  }
}
int main() {
  FIO;
#ifndef BOJ
  freopen("input.txt", "r", stdin);
#endif
  init();
  solve();
  return 0;
}
