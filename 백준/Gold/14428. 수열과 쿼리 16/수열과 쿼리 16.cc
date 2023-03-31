#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define FIO ios_base::sync_with_stdio(0);cin.tie(0); cout.tie(0);
#define endl "\n"
#define input freopen("input.txt", "r", stdin);
#define MOD 1000000007
typedef pair<int, int> pii;

int N,M;
pii* seg[400004];
pii arr[100001];
pii* init(int start, int end, int node) {
    if (start == end) return seg[node] = &arr[start];
    int mid = (start + end) / 2;
    pii* a = init(start, mid, node * 2);
    pii* b = init(mid + 1, end, node * 2 + 1);
    if (a->first < b->first || (a->first == b->first && a->second < b->second))
        return seg[node] = a;
    else
        return seg[node] = b;
}
pii* sum(int start, int end, int node, int left, int right) {
    if (left > end || right < start) return NULL;
    if (left <= start && end <= right) return seg[node];
    int mid = (start + end) / 2;
    pii* a = sum(start, mid, node * 2, left, right);
    pii* b = sum(mid + 1, end, node * 2 + 1, left, right);
    if (a == NULL)
        return b;
    if (b == NULL)
        return a;
    if (a->first < b->first||(a->first==b->first&&a->second<b->second))
        return a;
    else
        return b;
}
pii* update(int start, int end, int node, int index, int chan) {
    if (index<start || index>end) return seg[node];
    if (start == end&& end==index) {
        arr[index].first=chan;
        return &arr[index];
    }
    int mid = (start + end) / 2;
    pii* a = update(start, mid, node * 2, index, chan);
    pii* b = update(mid + 1, end, node * 2 + 1, index, chan);
    if (a->first < b->first || (a->first == b->first && a->second < b->second))
        return seg[node] = a;
    else
        return seg[node] = b;
}
int main() {
	FIO;
    cin >> N;
    for (int i = 1; i <= N; i++) {
        cin >> arr[i].first;
        arr[i].second = i;
    }
    init(1, N, 1);
    int a, b, c;
    cin >> M;
    while (M--) {
        cin >> a >> b >> c;
        if (a == 1)update(1, N, 1, b, c);
        else cout << sum(1, N, 1, b, c)->second << endl;
    }
}