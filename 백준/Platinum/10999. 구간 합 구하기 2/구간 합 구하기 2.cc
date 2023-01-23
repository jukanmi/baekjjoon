#include <iostream>
#include <vector>
#include <cmath>
#define FIO\
	ios_base::sync_with_stdio(0);\
	cin.tie(0); cout.tie(0);
using namespace std;
#define endl "\n"
typedef long long ll;
typedef struct renew {
    ll value = 0, lazy = 0;
}renew;
vector<ll> arr;
vector<renew> tree;
ll init(int start, int end, int idx) {
    if (start == end)
        return tree[idx].value = arr[start];
    int mid = (start + end) / 2;
    return tree[idx].value = init(start, mid, idx * 2) + init(mid + 1, end, idx * 2 + 1);
}
ll sum(int start, int end, int left, int right, int node) {
    if (end < left || right < start) return 0LL;
    if (tree[node].lazy) {
        tree[node].value += tree[node].lazy * (end - start + 1);//lazy 반영
        if (start != end) {
            tree[node * 2].lazy += tree[node].lazy;//노드 좌측에 lazy 반영
            tree[node * 2 + 1].lazy += tree[node].lazy;//노드 우측에 lazy 반영
        }
        tree[node].lazy = 0;
    }
    if (left <= start && end <= right) return tree[node].value;
    int mid = (start + end) / 2;
    return sum(start, mid, left, right, node * 2) + sum(mid + 1, end, left, right, node * 2 + 1);
}
void addLazy(int start, int end, int left, int right, int node, ll change) {
    if (tree[node].lazy) {
        tree[node].value += tree[node].lazy * (end - start + 1);//lazy 반영
        if (start != end) {
            tree[node * 2].lazy += tree[node].lazy;//노드 좌측에 lazy 반영
            tree[node * 2 + 1].lazy += tree[node].lazy;//노드 우측에 lazy 반영
        }
        tree[node].lazy = 0;
    }
    if (end < left || right<start) return;
    if (left <= start && end <=right) {
        tree[node].value += change*(end-start+1);
        if (start != end) {
            tree[node * 2].lazy += change;
            tree[node * 2 + 1].lazy += change;
        }
        return;
    }
    int mid = (start + end) / 2;
    addLazy(start, mid, left, right, node * 2, change); 
    addLazy(mid + 1, end, left, right, node * 2 + 1, change);
    tree[node].value = tree[node * 2].value + tree[node * 2 + 1].value;
}
int main() {
    FIO;
    //freopen("input.txt", "r", stdin);
    int N, M, K;
    cin >> N >> M >> K;
    arr.resize(N);
    tree.resize(N * 4);
    for (int i = 0; i < N; i++)
        cin >> arr[i];
    init(0, N - 1, 1);
    for (int i = 0; i < M + K; i++) {
        int a, b, c;
        ll d;
        cin >> a;
        if (a == 1) {
            cin >> a >> b >> d;
            addLazy(0, N-1, a-1, b-1, 1, d);
        }
        else {
            cin >> a >> b;
            cout << sum(0, N-1, a-1, b-1, 1) << endl;
        }
    }
}
