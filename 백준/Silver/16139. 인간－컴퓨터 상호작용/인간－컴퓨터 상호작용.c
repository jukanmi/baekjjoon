#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#define MAX 2147483647
#define ll long long
int main() {
    int S[27][200002] = { 0 }, z = 1;
    char tmp;
    while (1) {
        scanf("%c", &tmp);
        if (tmp == 10)break;
        S[tmp - 97][z]++;
        for (int i = 0; i < 27; i++) S[i][z + 1] = S[i][z];
        z++;
    }
    int t, s, e;
    scanf("%d", &t);
    while (t--) {
        scanf("\n%c%d%d", &tmp, &s, &e);
        printf("%d\n", S[tmp - 97][e+1] - S[tmp - 97][s]);


    }
}