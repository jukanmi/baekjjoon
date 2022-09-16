#include <stdio.h>
int A, len, N;
int dicrease[1030];
void fill(int n, int total)
{//A자리 감소수 추가하기
    if (n == A) {
        dicrease[len++] = total;
        return;
    }
    for (int i = 0; i < total % 10; i++) {
        long long num = total * 10 + i;
        fill(n + 1, num);
    }
    return;
}

int main() {
    scanf("%d", &N);
    if (N > 1022) {
        printf("-1");
        return 0;
    }
    else if (N == 1022) {
        printf("9876543210");
        return 0;
    }
    for (A = 0; A < 10; A++) {//자릿수
        int total = 0;
        for (int i = A; i < 10; i++) {
            fill(0, i);
        }
    }
    printf("%d", dicrease[N]);

}