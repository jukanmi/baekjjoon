#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cmath>
#include <map>
#include <set>
#include <list>
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

bool number[2500*5001] = {0};
bool solve(int n){
  if (n==1){
    cout << "YES\n1" << endl;
    return true;
  }
  if (n<3){
    cout << "NO" << endl;
    return true;
  }
  if (n==3){
    cout << "YES\n1 3 2" << endl;
    return true;
  }
vector<int> arr = {4,2,3};
for (int i=5; i <= n; i++) {
    arr.push_back(i);
    if (i%2==0){
      swap(arr[i-2], arr[i-3]);
    }
  }
  arr.push_back(1);
  cout << "YES\n";
  for (int i=0; i<arr.size(); i++) {
    cout << arr[i] << " ";
  }
  cout << endl;
  return 1;
}
void prime() {
  for (int i = 2; i <= 2500*5001; i++) {
    if (number[i]) continue;
    for (int j = i * 2; j <= 2500*5001; j += i) {
      number[j] = 1;
    }
  }
}
int main() {
  init();
  prime();
  int n;
  cin >> n;
  solve(n);
  return 0;
}
