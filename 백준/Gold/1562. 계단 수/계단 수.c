#include <stdio.h>
#define MAX 1000000000
int dp[101][10][1024],n,bit;
int main() {
    scanf("%d",&n);
    for (int i=1;i<10;i++)
        dp[1][i][1<<i] = 1;
    for (int i=1;i<n;i++) {
        for (int j=0;j<10;j++){
            for (int k=0;k<1024;k++){
                if (j<9){
                    bit=k|(1<<j+1);
                    dp[i+1][j+1][bit]+=dp[i][j][k];
                    dp[i+1][j+1][bit]%=MAX;
                }
                if (0<j){
                    bit=k|(1<<j-1);
                    dp[i+1][j-1][bit]+=dp[i][j][k];
                    dp[i+1][j-1][bit]%=MAX;
                }
            }
        }
    }
    int ans = 0;
    for (int i=0;i<10;i++){
        ans+=dp[n][i][1023];
        ans%=MAX;
    }
    printf("%d\n",ans);
    return 0;
}