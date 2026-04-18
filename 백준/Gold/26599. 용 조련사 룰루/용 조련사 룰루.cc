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


int main() {
  init();
  int n,m;
  cin >> n>>m;
  vector<pair<int, int>> v(n);
  for (int i = 0; i < n; i++) {
    cin >> v[i].first;
    v[i].second = i + 1;
  }
  sort(v.begin(), v.end());
  if (n < 4) {
    if (n==3){
      if (v[2].first - v[1].first > m || v[1].first - v[0].first > m) {
        cout << "NO";
        return 0;
      }
      }
      cout << "YES\n";
      for (auto& p : v) {
        cout << p.second << " ";
      }

    return 0;
  }
  if (v[n - 1].first - v[n - 2].first > m || v[n - 2].first - v[n - 3].first > m || v[n - 3].first - v[n - 4].first > m) {
    cout << "NO";
    return 0;
  }
  cout << "YES\n";
  cout << v[n - 1].second << " " << v[n - 2].second << " ";
  v.pop_back();
  v.pop_back();
  for (auto& p : v) {
    cout << p.second << " ";
  }
}
