#include <stdio.h>
#define cycle 1500000
#define divide 1000000
int main() {
    int fibo[cycle] = { 0,1 };
    long long n;
    scanf("%lld", &n);
    for (int i = 2; i < cycle; i++) {
        fibo[i] = fibo[i - 1] + fibo[i - 2];
        fibo[i] %= divide;
    }
    printf("%d\n", fibo[n % cycle]);
    return 0;
}