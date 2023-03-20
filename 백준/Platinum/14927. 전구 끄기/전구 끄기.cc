#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define FIO ios_base::sync_with_stdio(0);cin.tie(0); cout.tie(0);
#define endl "\n"
int N;
#define input freopen("input.txt", "r", stdin);
int ans = INT_MAX;
bool arr[18][18];
bool cpy[18][18];
bool into(int x, int y) { return 0 <= x && x < N && 0 <= y && y < N; }
void push(int x, int y) {
	if (into(x - 1, y)) 
		cpy[x - 1][y] = !cpy[x - 1][y];
	if (into(x + 1, y)) 
		cpy[x + 1][y] = !cpy[x + 1][y];
	if (into(x, y - 1)) 
		cpy[x][y - 1] = !cpy[x][y - 1];
	if (into(x, y + 1)) 
		cpy[x][y + 1] = !cpy[x][y + 1];
	cpy[x][y] = !cpy[x][y];
}
int main() {
	FIO
	//input
	cin >> N;
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			cin >> arr[i][j];
	for (int i = 0; i < 1 <<N; i++) {
		for (int x = 0; x < N; x++)
			for (int y = 0; y < N; y++)
				cpy[x][y] = arr[x][y];
		int cnt = 0;
		for (int j = 0; j < N; j++) {
			if (i & 1 << j) {
				cnt++;
				push(0, j);
			}
		}
		for (int a = 1; a < N; a++)
			for (int b = 0; b < N; b++)
				if (cpy[a - 1][b]) {
					push(a, b);
					cnt++;
				}
		bool flag = 1;
		for (int i = 0; i < N&&flag; i++)
			if (cpy[N - 1][i])
				flag = 0;
		ans = flag && ans > cnt ? cnt : ans;
	}
	if (ans == INT_MAX)
		puts("-1");
	else
		cout << ans << endl;
}