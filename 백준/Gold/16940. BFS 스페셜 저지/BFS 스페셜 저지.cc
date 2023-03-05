#include <bits/stdc++.h>
using namespace std;
#define FIO ios_base::sync_with_stdio(0);cin.tie(0); cout.tie(0);
int N;
vector<vector<int>> node;
bool find(vector<int>& arr, int ff) {
	int l = 0, r = arr.size() - 1;
	while (l <= r) {
		int m = (l + r) / 2;
		if (arr[m] <= ff)l = m + 1;
		else r = m - 1;
	}
	if (!l) return 0;
	return arr[l - 1] == ff ? 1 : 0;
}
int main() {
	FIO;
	cin >> N;
	node.resize(N + 1, vector<int>());
	for (int i = 0; i < N - 1; i++) {
		int a, b;
		cin >> a >> b;
		node[a].push_back(b);
		node[b].push_back(a);
	}
	vector<int> ans(N);
	for (int i = 0; i < N; i++)
		cin >> ans[i];
	for (int i = 1; i <= N; i++)
		sort(node[i].begin(), node[i].end());
	int idx = 1;
	if (ans[0] != 1) {
		puts("0");
		return 0;
	}
	queue<int> ss; ss.push(1);
	while (!ss.empty() && idx != N) {
		if (find(node[ss.front()], ans[idx]))
			ss.push(ans[idx++]);
		else
			ss.pop();
	}
	puts(idx==N?"1" : "0");
}