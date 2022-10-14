#include <stdio.h>
#include <string.h>
#define MAX 100000000

int N, map[16][16], bit;
int dp[16][1 << 16];
int min(int a, int b) { return a < b ? a : b; }
int tsp(int lastNode, int bitmask) {
    if (bitmask == bit) {
        if (map[lastNode][0] == 0) return MAX;
        else return map[lastNode][0];
    }
    if (dp[lastNode][bitmask] != -1) return dp[lastNode][bitmask];//저장되어있음
    dp[lastNode][bitmask] = MAX;
    for (int i = 0; i < N; i++) {
        if (map[lastNode][i] == 0) continue;
        if (bitmask & (1 << i)) continue;
        dp[lastNode][bitmask] = min(dp[lastNode][bitmask], tsp(i, bitmask | (1 << i)) + map[lastNode][i]);
    }
    return dp[lastNode][bitmask];
}
int main() {
    scanf("%d", &N);
    bit = (1 << N) - 1;
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            scanf("%d", &map[i][j]);
    memset(dp, -1, sizeof(dp));
    printf("%d", tsp(0, 1));
    return 0;
}