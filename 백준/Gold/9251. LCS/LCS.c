#include <stdio.h>
#include <stdlib.h>
#include <string.h>
char L[1001], S[1001];
int plus[1001][1001];
int maxx(int a, int b) { return a > b ? a : b; }
int main() {
    scanf("%s%s", L, S);
    int lenL = strlen(L), lenS = strlen(S);
    for (int i = 1; i <= lenL; i++) {
        for (int j = 1; j <= lenS; j++) {
            if (L[i-1] == S[j-1])
                plus[i][j] = plus[i - 1][j - 1] + 1;
            else
                plus[i][j] = maxx(plus[i - 1][j],plus[i][j-1]);
        }
    }
    printf("%d", plus[lenL][lenS]);
}