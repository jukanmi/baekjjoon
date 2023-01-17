#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define alpha "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ"
typedef long long ll;
char line[5000003];
int main() {
    int N;
    scanf("%d\n", &N);
    ll sum = 0;
    scanf("%s", line);
    char *ptr = strtok(line, alpha);
    while (ptr != NULL) {
        int num = atoi(ptr);
        if (999999 >= num) sum += num;
        ptr = strtok(NULL, alpha);
    }
    printf("%lld\n", sum);
}