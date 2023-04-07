#include <bits/stdc++.h>
using namespace std;
#define FIO ios_base::sync_with_stdio(0);cin.tie(0); cout.tie(0);
//#define time
#define endl "\n"

typedef long long ll;
typedef pair<int, ll> pil;
typedef pair<int, int> pii;
const int maxM = 400015;
const int maxN = 100005;
int M, N, K;
ll dist[maxM];
vector<pil> g[maxM];
vector<pii> a[maxN], b[maxN];
bool cmp(pil a, pil b) {
	return a.second > b.second;
}
ll dajistra() {
	priority_queue<pil, vector<pil>, decltype(&cmp)> pq(&cmp);
	pq.push({ 0,0 });
	while (!pq.empty()) {
		int cur = pq.top().first; ll Dist = pq.top().second;
		pq.pop();
		if (dist[cur] > Dist)continue;
		for (const pil node : g[cur]) {
			int next = node.first; ll nDist = node.second;
			if (dist[next] > nDist + Dist) {
				dist[next] = nDist + Dist;
				pq.push({ next,dist[next] });
			}
		}
	}
	if (dist[(K + 1) * 2] == 1LL << 62 && dist[(K + 1) * 2 + 1] == 1LL << 62) return -1;
	return min(dist[(K + 1) * 2], dist[(K + 1) * 2 + 1]);
}
int main() {
#ifdef time
		clock_t start, finish;
		double duration;
		start = clock();
		freopen("input.txt", "r", stdin);
#endif // time
		FIO;
		int T=1;
		//cin >> T;
		while (T--) {
			fill(dist, dist + maxM,1LL<<62);
			dist[0] = 0;
			cin >> M >> N >> K;
			a[0].emplace_back( 0,0 );
			b[0].emplace_back( 0,0 );
			bool flag = 0;
			for (int i = 1; i <= K; i++) {
				int x, y;
				cin >> y >> x;
				x--, y--;
				a[x].emplace_back(y, i);
				b[y].emplace_back(x, i);
				if (!x && !y) flag = 1;
			}
			a[N - 1].emplace_back(M - 1, K + 1);
			b[M - 1].emplace_back(N - 1, K + 1);
			for (int i = 1; i <= K; i++) {
				g[i * 2].emplace_back(i * 2 + 1, 1);
				g[i * 2 + 1].emplace_back(i * 2, 1);
			}
			if (flag) {
				g[0].emplace_back(1, 1);
				g[1].emplace_back(0, 1);
			}
			for (int i = 0; i < maxN; i++) {
				sort(a[i].begin(), a[i].end());
				sort(b[i].begin(), b[i].end());
			}
			for (int i = 0; i < maxN; i++) {
				for (int j = 0; j < (int)b[i].size() - 1; j++) {
					int Dist = b[i][j + 1].first - b[i][j].first;
					g[b[i][j].second * 2].emplace_back(b[i][j + 1].second * 2, Dist);
					g[b[i][j + 1].second * 2].emplace_back(b[i][j].second * 2, Dist);
				}
				for (int j = 0; j < (int)a[i].size() - 1; j++) {
					int Dist = a[i][j + 1].first - a[i][j].first;
					g[a[i][j].second * 2 + 1].emplace_back(a[i][j + 1].second * 2 + 1, Dist);
					g[a[i][j + 1].second * 2 + 1].emplace_back(a[i][j].second * 2 + 1, Dist);
				}
			}
			cout << dajistra() << endl;
		}
#ifdef time
	finish = clock();
	duration = (double)(finish - start) / CLOCKS_PER_SEC;
	cout << duration << "초\n";
#endif // time
}