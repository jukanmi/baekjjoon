#include <bits/stdc++.h>
using namespace std;
#define FIO ios_base::sync_with_stdio(0);cin.tie(0); cout.tie(0);
#define input freopen("input.txt", "r", stdin);
#define endl "\n"
typedef long long ll;
int cpy[21][200002];
int table(int n, int x, int m) {
	int cnt = 0;
	while (n) {
		if (n & 1)
			x = cpy[cnt][x];
		n >>= 1;
		cnt++;
	}
	return x;
}
int main() {
	int m, Q, n, x;
	FIO;
	cin >> m;
	for (int i = 1; i <= m; i++)
		cin >> cpy[0][i];
	for (int j = 0; j < 20; j++) {
		for (int i = 1; i <= m; i++)
			cpy[j + 1][i] = cpy[j][cpy[j][i]];
	}
	cin >> Q;
	while (Q--) {
		cin >> n >> x;
		cout << table(n, x,m) << endl;
	}
}