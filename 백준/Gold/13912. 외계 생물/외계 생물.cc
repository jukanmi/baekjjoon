#include <bits/stdc++.h>
using namespace std;
using vi = vector<int>;
using vvi = vector<vi>;
using ii = pair<int, int>;
using vii = vector<ii>;
using ll = long long;
#define endl "\n"
#define all(x) x.begin(), x.end()
const int INF = 987654321;
const int MOD = 1e9 + 7;
ll nCr[2050][2050];
void build() {
  nCr[0][0] = 1;
  for (int i = 1; i < 2050; i++) {
    nCr[i][0] = 1;
    for (int j = 1; j <= i; j++)
      nCr[i][j] = (nCr[i - 1][j - 1] + nCr[i - 1][j]) % MOD;
  }
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
#ifndef BOJ
  freopen("input.txt", "r", stdin);
#endif
  int H;
  cin >> H;
  build();
  ll DP[11] = {1,};
  DP[1] = 2;
  for (int i = 2; i <= H; i++) {
    DP[i] = nCr[(1 << (i + 1)) - 2][(1 << i) - 1] * ((DP[i - 1] * DP[i - 1]) % MOD);
    DP[i] %= MOD;
  }
  cout << DP[H] << endl;
  return 0;
}
