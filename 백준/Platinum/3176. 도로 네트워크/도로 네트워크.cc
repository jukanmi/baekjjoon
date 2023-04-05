#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define FIO ios_base::sync_with_stdio(0);cin.tie(0); cout.tie(0);
#define endl "\n"
#define input freopen("input.txt","r",stdin);
const int Max = 17;
int n;
class dp {
public:
	int next;
	int maxload=-1, minload=INT_MAX;
};
vector<pair<int,int> > node[100001];
vector<int> depth;
dp arr[17][100001];

void dfs(int cur, int dep) {
	for (pair<int,int>s : node[cur]) {
		if (depth[s.first] != -1) continue;	
		depth[s.first] = dep + 1;
		arr[0][s.first].next = cur;
		arr[0][s.first].maxload = s.second;
		arr[0][s.first].minload = s.second;
		dfs(s.first, dep + 1);
	}
}
void setspas() {
	for (int i = 0; i < 16; i++)
		for (int j = 1; j <= n; j++) {
			arr[i + 1][j].next = arr[i][arr[i][j].next].next;
			arr[i + 1][j].maxload = max(arr[i][j].maxload, arr[i][arr[i][j].next].maxload);
			arr[i + 1][j].minload = min(arr[i][j].minload, arr[i][arr[i][j].next].minload);
		}
}
pair<int, int> load;
void distance(int a, int b) {
	load.first = INT_MAX,load.second = -INT_MAX;
	if (depth[a] > depth[b])swap(a, b);
	for (int i = 16; i >= 0; i--)
		if (depth[a] <= depth[arr[i][b].next]) {
			load.first = min(load.first, arr[i][b].minload);
			load.second = max(load.second, arr[i][b].maxload);
			b = arr[i][b].next;
		}
	if (a == b) return;
	for (int i = 16; i >= 0; i--)
		if (arr[i][a].next != arr[i][b].next) {
			load.first = min(load.first, arr[i][a].minload);
			load.first = min(load.first, arr[i][b].minload);
			load.second = max(load.second, arr[i][a].maxload);
			load.second = max(load.second, arr[i][b].maxload);
			a = arr[i][a].next, b = arr[i][b].next;
		}
	load.first = min(load.first, arr[0][a].minload);
	load.first = min(load.first, arr[0][b].minload);
	load.second = max(load.second, arr[0][a].maxload);
	load.second = max(load.second, arr[0][b].maxload);
}
int main() {
	//input;
	FIO;
	cin >> n;
	depth.resize(n+1, -1);
	depth[1] = 0;
	arr[0][1].next = 1;
	for (int i=0;i<n-1;i++) {
		int a, b,c;
		cin >> a >> b >> c;
		node[a].push_back({ b,c });
		node[b].push_back({ a,c });
	}
	dfs(1, 0);
	setspas();
	int m;
	cin >> m;
	while (m--) {
		int a, b;
		cin >> a >> b;
		distance(a, b);
		cout << load.first << " " << load.second << endl;
	}
}

