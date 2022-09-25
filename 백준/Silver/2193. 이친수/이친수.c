#include <stdio.h>
int main() {
    long long num[2] = {0,1}, A, n;
    scanf("%lld", &n);
    for (int i = 1; i < n; i++) {
        A=num[0];
        num[0] += num[1];
        num[1] = A;
    }
        printf("%lld\n", num[0] + num[1]);
}
