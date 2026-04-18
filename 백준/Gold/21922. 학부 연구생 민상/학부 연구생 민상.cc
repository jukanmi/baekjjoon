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
int n,m;
int room[2001][2001];
bool visited[2001][2001][4];
void dfs(int x, int y,int r) {
  if (x < 0 || x >= n || y < 0 || y >= m) return ;
  if (visited[x][y][r]) return ;
  visited[x][y][r] = true;
  if (room[x][y] == 1 && (r==0||r==2)) return ; 
  if (room[x][y] == 2 && (r==3||r==1)) return ;
  if (room[x][y] == 3) {
    switch (r) {
      case 0: r=1 ; break;
      case 1: r=0 ; break;
      case 2: r=3 ; break;
      case 3: r=2 ; break;
    }
  }
  else if (room[x][y] == 4) {
    switch (r) {
      case 0: r=3 ; break;
      case 1: r=2 ; break;
      case 2: r=1 ; break;
      case 3: r=0 ; break;
    }
  }
  switch (r) {
    case 0: dfs(x, y-1, r); break;
    case 1: dfs(x+1, y, r); break;
    case 2: dfs(x, y +1, r); break;
    case 3: dfs(x - 1, y, r); break;
  }
}
int main() {
  init();
  cin >> n >> m;
  vector<pair<int, int>> start;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      cin >> room[i][j];
      if (room[i][j] == 9)
        start.push_back({i, j});
    }
  }
  for (auto& s : start) {
    dfs(s.first, s.second, 0);
    dfs(s.first, s.second, 1);
    dfs(s.first, s.second, 2);
    dfs(s.first, s.second, 3);
  }
  int ans=0;
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        ans+=(visited[i][j][0]||visited[i][j][1]||visited[i][j][2]||visited[i][j][3]);
      }
  }
  cout << ans << '\n';

  return 0;
}
