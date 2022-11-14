#include <stdio.h>
#define ll long long
ll init(int start, int end, int node);
ll sum(int start, int end, int node, int left, ll right);
void update(int start, int end, int node, int index, ll dif);
ll ST[4000001], arr[1000001];
int main() {
    int N, M, K, a, b, len = 0;
    ll k[10001], c;
    scanf("%d%d%d", &N, &M, &K);
    for (int i = 0; i < N; i++)
        scanf("%lld", &arr[i]);
    init(0, N - 1, 1);
    for (int i = 0; i < M + K; i++) {
        scanf("%d%d%lld", &a, &b, &c);
        if (a == 1)
            update(0, N - 1, 1, b-1, c - arr[b-1]);
        else
            k[len++] = sum(0, N - 1, 1, b-1, c-1);
    }
    for (int i = 0; i < K; i++)
        printf("%lld\n", k[i]);
    return 0;
}
ll init(int start, int end, int node) {
    if (start == end) return ST[node] = arr[start];
    int mid = (start + end) / 2;
    return ST[node] = init(start, mid, node * 2) + init(mid + 1, end, node * 2 + 1);
}
ll sum(int start, int end, int node, int left, ll right) {
    if (left > end || right < start) return 0;
    if (left <= start && end <= right) return ST[node];
    int mid = (start + end) / 2;
    return sum(start, mid, node * 2, left, right) + sum(mid + 1, end, node * 2 + 1, left, right);
}
void update(int start, int end, int node, int index, ll dif) {
    if (index<start || index>end) return;
    ST[node] += dif;
    if (start == end) {
        arr[index] += dif;
        return;
    }
    int mid = (start + end) / 2;
    update(start, mid, node * 2, index, dif);
    update(mid + 1, end, node * 2 + 1, index, dif);
}