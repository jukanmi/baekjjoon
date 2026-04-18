#include <iostream>
#include <vector>
#include <string>
#include <set>
#include <map>
#include <algorithm>
#include <cstring>

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

    int n,k;
    cin >> n >> k;
    int jsum=0, tsum=0;
    for (int i = 0; i < n; i++) {
        int j,t;
        cin >> j >> t;
        jsum += j;
        tsum += t;
        if (jsum>=k && tsum>=k){
            cout << 1;
            return 0;
        }
        else if (tsum >= k) {
            cout << -1;
            return 0;
        }
        else if (jsum+j/2>=k){
            cout << 1;
            return 0;
        }
        if (jsum + j/2-tsum>=50){
            cout << 1;
            return 0;
        }
    }
    cout << 0;

    return 0;
}