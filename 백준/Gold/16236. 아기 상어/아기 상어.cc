#include <iostream>
#include <queue>
#include <vector>
#include <map>
#include <string>
#include <algorithm>
#define endl "\n"
#define FIO ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
using namespace std;
struct place {
	int Oc[20][20];
	int Lc[2];
	int move;
};
typedef struct place cose;
queue<cose> q;
int N, level = 2, ans,eat,vis[20][20];
int check(int x, int y, int Oc[20][20]);
int main() {
	FIO
	cin >> N;
	cose start;
	for (int i=0;i<N;i++)
		for (int j = 0; j < N; j++) {
			cin >> start.Oc[i][j];
			if (start.Oc[i][j]==9)
				start.Lc[0] = i, start.Lc[1] = j, start.Oc[i][j] = 0;
		}
	start.move = 0;
	for (int i=0;i<N;i++)
		fill(vis[i], vis[i]+N, 0);
	vis[start.Lc[0]][start.Lc[1]] = 1;
	q.push(start);
	while (1) {
		bool flag = true;
		while (1) {
			if (q.empty()) {
				flag = false;
				break;
			}
			start = q.front();
			if (start.Oc[start.Lc[0]][start.Lc[1]] && start.Oc[start.Lc[0]][start.Lc[1]] < level) break;
			q.pop();
			if (check(start.Lc[0]-1, start.Lc[1], start.Oc)) {
				vis[--start.Lc[0]][start.Lc[1]] = 1;
				start.move++;
				q.push(start);
				start.move--;
				start.Lc[0]++;
			}
			if (check(start.Lc[0], start.Lc[1]-1, start.Oc)) {
				vis[start.Lc[0]][--start.Lc[1]] = 1;
				start.move++;
				q.push(start);
				start.move--;
				start.Lc[1]++;
			}
			if (check(start.Lc[0], start.Lc[1]+1, start.Oc)) {
				vis[start.Lc[0]][++start.Lc[1]] = 1;
				start.move++;
				q.push(start);
				start.move--;
				start.Lc[1]--;
			}
			if (check(start.Lc[0] + 1, start.Lc[1], start.Oc)) {
				vis[++start.Lc[0]][start.Lc[1]] = 1;
				start.move++;
				q.push(start);
				start.move--;
				start.Lc[0]--;
			}
		}
		if (flag) {// 가까운데 찾음
			while (!q.empty()) {
				if (q.front().move > start.move) break;
				if (!q.front().Oc[q.front().Lc[0]][q.front().Lc[1]] || !(q.front().Oc[q.front().Lc[0]][q.front().Lc[1]] < level)) {
					q.pop();
					continue;
				}
				if ((start.Lc[0] > q.front().Lc[0]) || (start.Lc[0] == q.front().Lc[0] && start.Lc[1] > q.front().Lc[1]))
					start = q.front();
				q.pop();
			}
			while (!q.empty()) q.pop();
			ans += start.move;
			eat++;
			//cout <<start.Lc[0] << " " << start.Lc[1] << "   " << level << " " << eat << endl;
			for (int i = 0; i < N; i++)
				fill(vis[i], vis[i] + N, 0);
			vis[start.Lc[0]][start.Lc[1]] = 1;
			start.move = 0;
			start.Oc[start.Lc[0]][start.Lc[1]] = 0;
			q.push(start);
			if (eat >= level) {
				level++;
				eat = 0;
			}
		}
		else
			break;
	}
	cout << ans;
}
int check(int x, int y, int Oc[20][20]) {
	return 0 <= x && x < N && 0 <= y && y < N && !vis[x][y] && Oc[x][y] <= level;
}