#include <stdio.h>
#include <stdlib.h>
#include <string.h>
char S[51], ans[51], one = -1, two[50];
int alpha[27], len;//A=65
int main() {
    scanf("%s", S);
    for (int i = 0; i < strlen(S); i++)
        alpha[S[i] - 65]++;
    for (int i = 0; i < 27; i++) {
        for (int j = 0; j < alpha[i] / 2; j++)
            two[len++] = i+65;
        if (alpha[i] % 2 == 1) {
            if (one != -1) {
                printf("I'm Sorry Hansoo");
                return 0;
            }
            one = i+65;
        }
    }
    for (int i = 0; i < len; i++)
        printf("%c", two[i]);
    if (one != -1) printf("%c", one);
    while (--len>=0) printf("%c", two[len]);
    return 0;
}