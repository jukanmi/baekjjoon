#include <bits/stdc++.h>
using namespace std;
using vi = vector<int>;
using vvi = vector<vi>;
using ii = pair<int, int>;
using vii = vector<ii>;

#define endl "\n"
#define all(x) x.begin(), x.end()
const int INF = 987654321;
const int MAXN = 1e5 + 5;
vector<array<int,3>> cook;
int visited[MAXN];
int parent(int n){
  if (visited[n] == n) return n;
  return visited[n] = parent(visited[n]);
}
bool unionFind(int n,int m){
  int a = parent(n);
  int b = parent(m);
  if (a == b) return 0;
  visited[a] = b;
  return 1;
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
#ifndef BOJ
  freopen("input.txt", "r", stdin);
#endif
  int n,m;
  cin >> n >> m;
  for (int i=0;i<=n;i++){
    visited[i] = i;
  }
  cook.resize(m);
  for (int i = 0; i < m; i++){
    int a,b,c;
    cin >> a >> b >> c;
    cook[i] = {c,a,b};
  }
  sort(all(cook));
  int ans = 1;
  while (ans<n){
    auto& target = cook[ans-1];
    if (target[0] !=ans || !unionFind(target[1],target[2]))
      break;
    ans++;
  }
  cout << ans << endl;
  return 0;
}
