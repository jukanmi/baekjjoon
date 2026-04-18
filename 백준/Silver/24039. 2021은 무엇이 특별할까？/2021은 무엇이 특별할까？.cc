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
int number[201];
vector<int>primeNumbers;
void prime() {
  for (int i = 2; i <= 200; i++) {
    if (number[i]) continue;
    primeNumbers.push_back(i);
    for (int j = i * 2; j <= 200; j += i) {
      number[j] = 1;
    }
  }
}
int main() {
  init();
  int n;
  cin >> n;
  prime();
  for (int i=0;i<primeNumbers.size();i++) {
    if (primeNumbers[i]*primeNumbers[i+1] > n) {
      cout << primeNumbers[i]*primeNumbers[i+1] << endl;
      break;
    }
  }

  return 0;
}
