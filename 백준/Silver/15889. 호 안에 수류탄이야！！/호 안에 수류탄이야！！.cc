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

int arr[51];
int main() {
    init();

    int n;
    cin >> n;
    vector<pair<int, int>> v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i].first;
    }
    if (n==1){
        cout << "권병장님, 중대장님이 찾으십니다" << endl;
        return 0;
    }
    for (int i = 0; i < n; i++) {
        cin >> v[i].second;
    }
    sort(v.begin(), v.end());
    int longerRange =0;
    for (int i = 0; i < n-1; i++) {
        longerRange = max(longerRange, v[i].second + v[i].first);
        //cout << "Current longer range: " << longerRange << endl;
        if (longerRange < v[i+1].first)
            break;
    }
    if (longerRange >= v[n-1].first) {
        cout << "권병장님, 중대장님이 찾으십니다" << endl;
    } else {
        cout << "엄마 나 전역 늦어질 것 같아" << endl;
    }
    return 0;
}