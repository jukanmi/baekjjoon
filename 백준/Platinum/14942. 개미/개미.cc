#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define FIO ios_base::sync_with_stdio(0);cin.tie(0); cout.tie(0);
#define endl "\n"
#define input freopen("input.txt", "r", stdin);





pair<int, int> graph[17][100001];
vector<vector<pair<int, int> > > neibor;
void setting(vector<bool>& vis, int cur) {

	if (!vis[cur]) {
		vis[cur] = 1;
		for (pair<int, int> s : neibor[cur]) {
			if (vis[s.first]) continue;
			graph[0][s.first].first = cur;
			graph[0][s.first].second = s.second;
			setting(vis, s.first);
		}
	}
}
int table(int ant, int energy) {
	bool flag;
	do {
		flag = 0;
		for (int i = 16; i >= 0; i--) {
			if (graph[i][ant].second <= energy) {
				energy -= graph[i][ant].second;
				ant=graph[i][ant].first;
				flag = 1;
				break;
			}
		}
	} while (flag && ant != 1);
	return ant;
}
int main() {
	FIO; 
	int N;
	cin >> N;
	vector<int> arr(N);
	for (int i = 0; i < N; i++)
		cin >> arr[i];
	vector<bool> vis(N + 1, 0);
	neibor.resize(N+1,vector<pair<int,int> >());
	for (int i = 0; i < N - 1; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		neibor[a].push_back({ b,c });
		neibor[b].push_back({ a,c });
	}
	graph[0][1].first = 1;
	setting(vis, 1);
	for (int i=0;i<16;i++)
		for (int j = 1; j <= N; j++) {
			graph[i + 1][j].first = graph[i][graph[i][j].first].first;
			graph[i + 1][j].second = graph[i][j].second + graph[i][graph[i][j].first].second;
		}
	for (int i = 0; i < N; i++)
		cout << table(i + 1, arr[i]) << endl;
}