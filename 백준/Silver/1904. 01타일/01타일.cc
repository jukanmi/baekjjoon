#include <iostream>
using namespace std;

int main() {
    int lengh, dp[1000001];
    cin >> lengh;
    dp[1] = 1; dp[2] = 2;
    for (int x = 3; x <= lengh; x++) {
        int ddp = dp[x - 2] + dp[x - 1];
        if (ddp >= 15746)
            ddp %= 15746;
        dp[x] = ddp;
    }
    cout << dp[lengh];
}