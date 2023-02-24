#include <bits/stdc++.h>
using namespace std;
#define FIO ios_base::sync_with_stdio(0);cin.tie(0); cout.tie(0);
int N, K, X;
int spe[81],str[81];
bool dp[81][81][16001];
int main() {
    //freopen("input.txt", "r", stdin);
    FIO;
    cin >> N >> K >> X;
    for (int j=0;j<=N;j++)
        dp[j][0][0] = 1;
    for (int i = 1; i <= N; i++)
        cin >> str[i] >> spe[i];
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= min(i,K); j++) {
            for (int k = 0; k <= X*j; k++) {
                if (k >= spe[i])
                    dp[i][j][k] = dp[i - 1][j - 1][k - spe[i]] || dp[i - 1][j][k];
                else
                    dp[i][j][k] = dp[i - 1][j][k];
            }
        }
    }
    int ans = -1;
    for (int i = 0; i <= K * X; i++) {
        if (dp[N][K][i])
            ans = max(ans, i * (K * X - i));
    }
    cout << ans << endl;
    return 0;
}
/*
6 3 6
0 6
1 5
2 4
5 1
3 3
1 5
*/