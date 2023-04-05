#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define FIO ios_base::sync_with_stdio(0);cin.tie(0); cout.tie(0);
#define endl "\n"
#define input freopen("input.txt","r",stdin);

int dp[50001];
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n, k, start;
    cin >> n;
    dp[0] = 0, dp[1] = 1;
    for (int i = 2; i < n + 1; i++) {
        k = 4;
        int sq = sqrt(i);
        for (int j = 1; j < sq + 1; j++) {
            k = min(k, dp[i - j * j]);
        }
        dp[i] = k + 1;
    }
    cout << dp[n];
    return 0;
}