#include <bits/stdc++.h>
using namespace std;
using vi = vector<int>;
using vii = vector<pair<int, int>>;
using ii = pair<int, int>;
#define endl "\n"
#define all(x) x.begin(), x.end()
const int MAXN = 1e2 + 4;
int n, m, h;
vii milk;
bool drink[MAXN];
int dist(ii a, ii b) {
  return abs(a.first - b.first) + abs(a.second - b.second);
}
void solve(int cur, int &ans, int milks, int health) {
  auto curs = milk[cur];
  if (cur == milk.size()-1 && milks) {
    ans = max(ans, milks - 1);
    return;
  }
  for (int i = 0; i < milk.size(); i++) {
    if (drink[i] || i == cur)
      continue;
    int d = dist(milk[cur], milk[i]);
    if (d <= health) {
      drink[i] = true;
      solve(i, ans, milks + 1, health - d + h);
      drink[i] = false;
    }
  }
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
#ifndef BOJ
  freopen("input.txt", "r", stdin);
#endif
  cin >> n >> m >> h;
  ii house;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      int tmp;
      cin >> tmp;
      if (tmp == 1)
        house = {i, j};
      else if (tmp == 2)
        milk.push_back({i, j});
    }
  }
  milk.push_back(house);
  int ans = 0;
  solve(milk.size() - 1, ans, 0, m);
  cout << ans << endl;
  return 0;
}
