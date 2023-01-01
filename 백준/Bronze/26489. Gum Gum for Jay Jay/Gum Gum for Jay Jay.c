#include<stdio.h>

int main() {
    char buf[25];
    int ans = 0;
    while (gets(buf))
        ans++;
    printf("%d", ans);
}