#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define FIO ios_base::sync_with_stdio(0);cin.tie(0); cout.tie(0);
#define endl "\n"
#define maxfast 16
int N;
vector<vector<int> > arr;
vector<int> depth;
vector<bool>parent;
vector<vector<int> >fastup;
void dfs(int idx, int cnt, vector<int>& upper) {
	depth[idx] = cnt;
	for (int p = maxfast; p >=0; p--) {
		int fast = upper.size() - (1 << p)-1;
		if (fast >= 0)
			fastup[idx][p] = upper[fast];
	}
	for (int s : arr[idx])
		if (!parent[s]) {
			parent[s] = 1;
			upper.push_back(s);
			dfs(s, cnt + 1,upper);
			upper.pop_back();
		}
}

int lca(int a, int b) {
	if (depth[a] > depth[b])
		swap(a, b);
	for (int i = maxfast; i >=0  && depth[a] != depth[b]; i--)
		if (fastup[b][i]&&depth[fastup[b][i]] >= depth[a])
			b = fastup[b][i];
	int ans = a;
	for (int i = maxfast; i >= 0 && a != b; i--) {
		if (fastup[b][i] && fastup[a][i] && fastup[b][i] != fastup[a][i]) {
			b = fastup[b][i];
			a = fastup[a][i];
		}
		ans = fastup[a][i];
	}
	return ans;
}
int main() {
	FIO;
	//freopen("input.txt", "r", stdin);
	cin >> N;
	arr.resize(N + 1,vector<int>());
	depth.resize(N + 1, 0);
	parent.resize(N + 1, 0);
	fastup.resize(N + 1, vector<int>(maxfast+1,0));
	for (int i = 0; i < N-1; i++) {
		int a, b;
		cin >> a >> b;
		arr[a].push_back(b);
		arr[b].push_back(a);
	}
	parent[1] = 1;
	vector<int> d;
	d.push_back(1);
	dfs(1, 0,d);
	int M;
	cin >> M;
	while (M--) {
		int a, b;
		cin >> a >> b;
		cout << lca(a, b) << endl;
	}
}