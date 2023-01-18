#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
int N, M, arr[100000], s, e, ans = INT_MAX;
int q(const void* w, const void* e) { return *(int*)w - *(int*)e; }
int main() {
    scanf("%d%d", &N, &M);
    for (int i = 0; i < N; i++)
        scanf("%d", &arr[i]);
    qsort(arr, N, 4, q);
    while (s < N && e < N) {
        if (arr[s] - arr[e] >= M) {
            ans = arr[s] - arr[e] < ans ? arr[s] - arr[e] : ans;
            e++;
        }
        else s++;
    }
    printf("%d\n", ans);
}