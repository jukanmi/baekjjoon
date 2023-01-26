#include <stdio.h>
#include <limits.h>
int N, M, space[1000][1000], ans = INT_MAX,arr[1000][1000][3];
int min(int a, int b) { return a < b ? a : b; }
int min4(int a, int b, int c, int d) { return min(a, b) < min(c, d) ? min(a, b) : min(c, d); }
int main() {
    scanf("%d%d", &N, &M);
    for (int i = 0; i < N; i++)
        for (int j = 0; j < M; j++) {
            scanf("%d", &space[i][j]);
            arr[i][j][0] = INT_MAX, arr[i][j][1] = INT_MAX, arr[i][j][2] = INT_MAX;
        }
    for (int i = 0; i < M; i++)
        arr[0][i][0] = space[0][i], arr[0][i][1] = space[0][i], arr[0][i][2] = space[0][i];
    for (int i = 1; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (0 < j) arr[i][j][2] = min(arr[i - 1][j - 1][0], arr[i - 1][j - 1][1])+space[i][j];
            arr[i][j][1] = min(arr[i - 1][j][0], arr[i - 1][j][2]) + space[i][j];
            if (j < M - 1) arr[i][j][0] = min(arr[i - 1][j + 1][1], arr[i - 1][j + 1][2]) + space[i][j];
        }
    }
    for (int i = 0; i < M; i++)
        ans = min4(arr[N - 1][i][0], arr[N - 1][i][1], ans, arr[N - 1][i][2]);
    printf("%d\n", ans);
}