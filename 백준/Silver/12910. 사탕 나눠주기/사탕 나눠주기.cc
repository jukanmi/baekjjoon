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
    cin>>n;
    for(int i=0; i<n; i++) {
        int tmp;
        cin>>tmp;
        arr[tmp-1]++;
    }
    int ans=0;
    for (int i=0; i<n; i++) {
        int tmp = 1;
        for (int j=0; j<=i; j++) {
           tmp*= arr[j];
        }
        ans += tmp;
    }
    cout << ans;
    return 0;
}