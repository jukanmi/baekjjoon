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

int number[100001];
vector<int> primeNumbers={1};
void prime() {
  for (int i = 2; i <= 100000; i++) {
    if (number[i]) continue;
    primeNumbers.push_back(i);
    for (int j = i * 2; j <= 100000; j += i) {
      number[j] = 1;
    }
  }
}

int main() {
  init();
  prime();
  int n,k;
  cin >> n;
  cin >> k;
  int ans = 0;
  for (int j = 1; j <= n; j++) {
    auto it = upper_bound(primeNumbers.begin(), primeNumbers.end(), k);
    for (auto prime = it; prime != primeNumbers.end(); prime++) {
      if (*prime > j) break;
      if (j % *prime == 0) {
        ans++;
        //cout << j << " is divisible by " << *prime << endl;
        break;
      }
    }
    
  }
  cout << n-ans << endl;
  return 0;
}
