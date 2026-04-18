#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cmath>
#include <map>
#include <set>
#include <stack>
#include <queue>
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


int EntoInt[26];
int e2n(string s, vector<int>& arr) {
  int res = 0;
  for (char& c: s){
    res = res * 10 + arr[EntoInt[c - 'A']];
  }
  return res;
}
bool check(vector<string>& E, vector<int>& arr){
  int n = E.size();
  int ans = 0;
  if (arr[EntoInt[E[n-1][0]-'A']] == 0 && E[n-1].size() > 1)
  return false; // leading zero check
  for (int i=0;i<n-1;i++){
    if (arr[EntoInt[E[i][0]-'A']] == 0 && E[i].size() > 1) {
      return false; // leading zero check
    }
    ans += e2n(E[i], arr);
  }
  return ans == e2n(E[n-1], arr);
}
void checkAll(vector<string>& E, int cnt,int cur,int& ans, vector<int>& arr, vector<bool>& vis) {
  if (cur == cnt) {
    if (check(E, arr)){
      ans++;
    }
    return;

  }
  for (int i=0;i<10;i++){
    if (!vis[i]){
      vis[i] = true;
      arr[cur] = i;
      checkAll(E,cnt,cur+1,ans,arr,vis);
      vis[i] = false;
    }
  }
}
int main() {
  init();
  
  while (1){
    int T;
    cin >> T;
    if (T == 0) break;
    vector<string> E(T);
    for (int i=0;i<T;i++){
      string s;
      cin >> E[i];
    }
    
  int cnt = 0;
  bool found[26] = {false};
  for (auto& s: E) {
    for (char c: s) {
      if (found[c - 'A']) continue;
      found[c - 'A'] = true;
      EntoInt[c - 'A'] = cnt;
      cnt++;
    }
  }
  int ans = 0;
  vector<int> arr(cnt, -1);
  vector<bool> vis(10, false);
  checkAll(E,cnt,0,ans,arr,vis);
  cout << ans << endl;
  }
  return 0;
}