#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
#include <string.h>
#include <queue>
using namespace std;

int N, M, V;
vector<pair<int, int> > a;
bool visited[1001];

bool compare(pair<int, int> a, pair<int, int> b) {
	if (a.first == b.first) return a.second < b.second;
	else return a.first < b.first;
}


void dfs(int t) {
	cout << t << " ";
	visited[t] = true;
	for (int i = 0; i < M; i++) {
		if (a[i].first == t && visited[a[i].second] == false) {
			dfs(a[i].second);
		}
		else if (a[i].second == t && visited[a[i].first] == false) {
			dfs(a[i].first);
		}
	}
}

void bfs(int t) {
	queue<int> q;
	q.push(t);
	visited[t] = true;
	int x;

	while (q.empty() == false) {
		x = q.front();
		cout << x << " ";
		q.pop();
		for (int i = 0; i < M; i++) {
			if (a[i].first == x && visited[a[i].second] == false) {
				q.push(a[i].second);
				visited[a[i].second] = true;
			}
			else if (a[i].second == x && visited[a[i].first] == false) {
				q.push(a[i].first);
				visited[a[i].first] = true;
			}
		}

	}

}


int main() {

	cin >> N >> M >> V;

	int x, y;

	memset(visited, false, sizeof(visited));

	for (int i = 0; i < M; i++) {
		cin >> x >> y;
		if (x == y) continue;
		else if (x > y) a.push_back(make_pair(y, x));
		else a.push_back(make_pair(x, y));
	}
	sort(a.begin(), a.end(), compare);
		dfs(V);
		cout << endl;
		memset(visited, false, sizeof(visited));
		bfs(V);

	return 0;
}