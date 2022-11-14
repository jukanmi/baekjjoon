#include <stdio.h>
#define ll long long
ll init(int start, int end, int node, ll ST[], ll arr[]);
ll sum(int start, int end, int node, int left, ll right, ll ST[]);
void update(int start, int end, int node, int index, ll dif, ll ST[], ll a[]);
int main() {
    int N, M, K, a, b, len = 0;
    ll seg_tree[4000001] = { 0 }, k[10001], arr[1000001], c;
    scanf("%d%d%d", &N, &M, &K);
    for (int i = 0; i < N; i++)
        scanf("%lld", &arr[i]);
    init(0, N - 1, 1, seg_tree, arr);
    for (int i = 0; i < M + K; i++) {
        scanf("%d%d%lld", &a, &b, &c);
        if (a == 1)
            update(0, N - 1, 1, b-1, c - arr[b-1], seg_tree,arr);
        else
            k[len++] = sum(0, N - 1, 1, b-1, c-1, seg_tree);
    }
    for (int i = 0; i < K; i++)
        printf("%lld\n", k[i]);
    /*
    for (int i = 1; seg_tree[i] != 0; i++)
        printf("%lld ", seg_tree[i]);
    printf("\n");
    */
    return 0;
}
ll init(int start, int end, int node, ll ST[], ll arr[]) {
    if (start == end) return ST[node] = arr[start];
    int mid = (start + end) / 2;
    return ST[node] = init(start, mid, node * 2, ST, arr) + init(mid + 1, end, node * 2 + 1, ST, arr);
}
ll sum(int start, int end, int node, int left, ll right, ll ST[]) {
    if (left > end || right < start) return 0;
    if (left <= start && end <= right) return ST[node];
    int mid = (start + end) / 2;
    return sum(start, mid, node * 2, left, right, ST) + sum(mid + 1, end, node * 2 + 1, left, right, ST);
}
void update(int start, int end, int node, int index, ll dif, ll ST[], ll arr[]) {
    if (index<start || index>end) return;
    ST[node] += dif;
    if (start == end) {
        arr[index] += dif;
        return;
    }
    int mid = (start + end) / 2;
    update(start, mid, node * 2, index, dif, ST, arr);
    update(mid + 1, end, node * 2 + 1, index, dif, ST, arr);
}