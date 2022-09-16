#include <stdio.h>
int max(int a, int b) { return a > b ? a : b; }
void bag_algo(int itemlen, int dp[][100001],int weight,int bag[][2]) {
    for (int i = 1; i <= itemlen; i++) {
        for (int j = 1; j <= weight; j++) {
            if (j >= bag[i][0])
                dp[i][j] = max(dp[i-1][j- bag[i][0]]+bag[i][1],dp[i-1][j]);
            else
                dp[i][j] = dp[i - 1][j];
        }
    }
    /*
    for (int i = 0; i <= itemlen; i++) {
        for (int j = 0; j <= weight; j++)
            printf("%2d ", dp[i][j]);
        printf("\n");
    }
    */
    printf("%d", dp[itemlen][weight]);
}
int main() {
    int N, W, dp[101][100001], bag[101][2];//bag=[무게,가치]
    scanf("%d %d", &N, &W);
    for (int i = 1; i <= N; i++)
        scanf("%d %d", &bag[i][0], &bag[i][1]);
    bag_algo(N, dp,W,bag);
    return 0;
}