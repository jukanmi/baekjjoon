#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define FIO ios_base::sync_with_stdio(0);cin.tie(0); cout.tie(0);
#define endl "\n"
#define input freopen("input.txt", "r", stdin);
int N, M;
class seg {
public:
	int press=0;
	bool lazy = 0;
	seg(){}

};
vector<seg*> segments;
vector<bool> arr;
int fid(int s, int e, int l, int r, int idx) {
	if (r < s || e < l) return 0;
	if (l <= s && e <= r)
		return segments[idx]->press;
	int m = (s + e) / 2;
	if (segments[idx]->lazy) {
		segments[idx * 2]->press = m - s + 1 - segments[idx * 2]->press;
		segments[idx * 2]->lazy = !segments[idx * 2]->lazy;
		segments[idx * 2 + 1]->press = e - m - segments[idx * 2 + 1]->press;
		segments[idx * 2 + 1]->lazy = !segments[idx * 2 + 1]->lazy;
		segments[idx]->lazy = 0;
	}
	return fid(s, m, l, r, idx * 2) + fid(m + 1, e, l, r, idx * 2 + 1);
}
int revse(int s, int e, int l, int r,int idx) {
	if (r < s || e < l) return segments[idx]->press;
	if (l <= s && e <= r) {
		segments[idx]->press = e - s + 1 - segments[idx]->press;
		segments[idx]->lazy = !segments[idx]->lazy;
		return segments[idx]->press;
	}
	int m = (s + e) / 2;
	if (segments[idx]->lazy) {
		segments[idx * 2]->press = m - s + 1 - segments[idx * 2]->press;
		segments[idx * 2]->lazy = !segments[idx * 2]->lazy;
		segments[idx * 2 + 1]->press = e - m - segments[idx * 2 + 1]->press;
		segments[idx * 2 + 1]->lazy = !segments[idx * 2 + 1]->lazy;
		segments[idx]->lazy = 0;
	}
	return segments[idx]->press=revse(s, m, l, r, idx * 2)+revse(m + 1, e, l, r, idx * 2 + 1);
}
int main() {
    FIO;
	//input
	cin >> N >> M;
	segments.resize(N * 4);
	for (int i = 0; i < 4 * N; i++)
		segments[i] = new seg();
	while (M--) {
		int a, b, c;
		cin >> a >> b >> c;
		if (a == 0)
			revse(1, N, b, c, 1);
		else
			cout << fid(1, N, b, c, 1) << endl;
	}
}