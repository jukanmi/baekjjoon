#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#define ll long long
#define MAX 2100000000
#define MOD 1000000007
int q(const void* w, const void* e) { return (int*)w - (int*)e; }
int vcal(int a, int b, int cal);
void func(int N, int A[], int cal[], int* min, int* max, int F, int ca);
int main() {
    int N, A[11], cal[4], min = MAX, max = -MAX;
    scanf("%d", &N);
    for (int i = 0; i < N; i++)
        scanf("%d", &A[i]);
    for (int i = 0; i < 4; i++)
        scanf("%d", &cal[i]);
    func(N, A, cal, &min, &max, 0, A[0]);
    printf("%d\n%d", max, min);
}
int vcal(int a, int b, int s) {
    if (s == 0) return a + b;
    if (s == 1) return a - b;
    if (s == 2) return a * b;
    if (s == 3) return a / b;
}

void func(int N, int A[], int cal[], int* min, int* max, int F, int ca) {
    if (F >= N - 1) {
        *min = *min > ca ? ca : *min;
        *max = *max < ca ? ca : *max;
        return;
    }
    for (int i = 0; i < 4; i++) {
        if (cal[i]) {
            cal[i]--;
            func(N, A, cal, min, max, F + 1, vcal(ca, A[F+1], i));
            cal[i]++;
        }
    }
    return;
}