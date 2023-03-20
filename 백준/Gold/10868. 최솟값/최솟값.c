#include <stdio.h>
#include <limits.h>
int min(int a, int b) { return a < b ? a : b; }
int N, M, arr[100001];
int seg[400001];
int setup(int i, int s, int e) {
    if (s == e)
        return seg[i] = arr[s];
    return seg[i] = min(setup(i * 2, s, (s + e) / 2), setup(i * 2 + 1, (s + e) / 2 + 1, e));
}
int find(int s, int e, int i, int l, int r) {
    if (r < s || e < l)return INT_MAX;
    if (s <= l && r <= e) return seg[i];
    return min(find(s, e, i * 2, l, (l + r) / 2), find(s, e, i * 2 + 1, (l + r) / 2 + 1, r));
}
int main() {
    scanf("%d%d", &N, &M);
    for (int i = 1; i <= N; i++)
        scanf("%d", &arr[i]);
    setup(1, 1, N);
    for (int i = 0; i < M; i++) {
        int a, b;
        scanf("%d%d", &a, &b);
        printf("%d\n", find(a, b, 1, 1, N));
    }
}