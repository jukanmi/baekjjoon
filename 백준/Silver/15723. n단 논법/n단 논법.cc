#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cmath>
#include <map>
#include <set>

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
bool graph[27][27];
void floyd() {
  for (int k = 0; k < 26; k++) {
    for (int i = 0; i < 26; i++) {
      for (int j = 0; j < 26; j++) {
        if (graph[i][k] && graph[k][j]) {
          graph[i][j] = 1;
        }
      }
    }
  }
}
int main() {
  init();
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) {
    char a,b;
    string s;
    cin >> a>>s>>b;
    graph[a-'a'][b-'a'] = 1;
  }
  floyd();
  int m;
  cin >> m;
  for (int i = 0; i < m; i++) {
    char a, b;
    string s;
    cin >> a >> s >> b;
    if (graph[a - 'a'][b - 'a'] == 1) {
      cout << "T" << endl;
    } else {
      cout << "F" << endl;
    }
  }
  return 0;
}
