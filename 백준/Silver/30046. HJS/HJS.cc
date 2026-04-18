#include <bits/stdc++.h>
using namespace std;
using ll = long long;
void init() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cout << fixed;
  //cout.precision(1);
#ifndef BOJ
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
#endif
}
//a<b를 만족시키는 HJS의 조건
vector<char> comparing(string a, string b){
  vector<char> result;
  int n = a.size();
  for (int i=0; i<n; i++){
    if (a[i]!=b[i]){
      result.push_back(a[i]);
      result.push_back(b[i]);
    }
  }
  return result;
}
int main() {
  init();
  int n;
  cin >> n;
  string p,q,r;
  cin >> p >> q >> r;
  auto result1 = comparing(p, q);
  auto result2 = comparing(q, r);
  if (result1.size() == 0 || result2.size() ==0||(result1[0] == result2[1] && result1[1] == result2[0])) {
    cout << "Hmm...";
  } 
  else
  {
    cout << "HJS! HJS! HJS!";
  }
}
