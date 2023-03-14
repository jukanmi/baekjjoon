#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define FIO ios_base::sync_with_stdio(0);cin.tie(0); cout.tie(0);
#define endl "\n"
int N;
vector<vector<int> > arr;
vector<int> depth,parent,fastup;
void dfs(int idx, int cnt, vector<int>& upper,int start) {
	depth[idx] = cnt;
	if (depth[upper[start]] * depth[upper[start]] < cnt - 1)
		start++;
	fastup[idx] = upper[start];
	for (int s : arr[idx])
		if (!parent[s]) {
			parent[s] = idx;
			upper.push_back(s);
			dfs(s, cnt + 1,upper,start);
			upper.pop_back();
		}
}

int lca(int a, int b) {
	if (depth[a] > depth[b])
		swap(a, b);
	while (depth[fastup[b]] > depth[a])//쾌속이동
		b = fastup[b];
	while (depth[b] > depth[a])//천천이동
		b = parent[b];
	while (fastup[fastup[a]] != fastup[fastup[b]]) {
		a = fastup[a];
		b = fastup[b];
	}
	while (a != b) {
		a = parent[a];
		b = parent[b];
	}
	return a;
}
int main() {
	FIO;
	cin >> N;
	arr.resize(N + 1,vector<int>());
	depth.resize(N + 1, 0);
	parent.resize(N + 1, 0);
	fastup.resize(N + 1, 0);
	for (int i = 0; i < N-1; i++) {
		int a, b;
		cin >> a >> b;
		arr[a].push_back(b);
		arr[b].push_back(a);
	}
	parent[1] = -1;
	fastup[1] = -1;
	vector<int> d;
	d.push_back(1);
	dfs(1, 0,d,0);
	int M;
	cin >> M;
	while (M--) {
		int a, b;
		cin >> a >> b;
		cout << lca(a, b) << endl;
	}
}