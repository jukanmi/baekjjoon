#include <stdio.h>
#include <stdlib.h>
#include <string.h>
char L[1002], S[1002], ans[1002];
int plus[1002][1002],len;
int maxx(int a, int b) { return a > b ? a : b; }
int main() {
    scanf("%s%s", L, S);
    int lenL = strlen(L), lenS = strlen(S);
    for (int i = 1; i <= lenL; i++) {
        for (int j = 1; j <= lenS; j++) {
            if (L[i - 1] == S[j - 1])
                plus[i][j] = plus[i - 1][j - 1] + 1;
            else
                plus[i][j] = maxx(plus[i - 1][j], plus[i][j - 1]);
        }
    }
    int x = lenL,y=lenS;
    printf("%d\n",plus[x][y]);
    while (plus[x][y] > 0) {
        if (plus[x][y] == plus[x - 1][y])
            x--;
        else if (plus[x][y] == plus[x][y - 1])
            y--;
        else if (plus[x][y]==plus[x-1][y-1]+1){
            ans[len++] = S[y-1]; x--; y--;
        }
    }
    for (int i=len-1;i>=0;i--)
        printf("%c",ans[i]);
    return 0;
}