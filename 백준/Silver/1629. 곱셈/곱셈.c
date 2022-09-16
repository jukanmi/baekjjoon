#include <stdio.h>
int a, b, c;
int func(int a, int b) {
    if (b > 1) {
        long long re = func(a, b / 2);
        if (b % 2)
            return ((re * re) % c * a) % c;
        else
            return (re * re) % c;
    }
    else
        return a;
}
int main() {
    scanf("%d %d %d", &a, &b, &c);
    printf("%d", func(a % c, b));
}
