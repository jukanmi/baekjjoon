#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define FIO ios_base::sync_with_stdio(0);cin.tie(0); cout.tie(0);
#define endl "\n"
#define input freopen("input.txt", "r", stdin);
class point {
public:
	ll x, y;
	ll rx = 0, ry = 0;
	point(ll a, ll b) {
		x = a, y = b;
	}
	void set(ll mx, ll my) {
		rx = x - mx, ry = y - my;
	}
};
int ccw(point* a, point* b, point* c) {
	ll cul = a->x * b->y + b->x * c->y + c->x * a->y - b->x * a->y - c->x * b->y - a->x * c->y;
	if (cul > 0) return 1;
	if (cul < 0) return -1;
	return 0;
}
bool down(point* a, point* b) {
	return a->x < b->x || (a->x == b->x && a->y < b->y);
}
bool cmp(point* a, point* b) {
	if (a->ry * b->rx != b->ry * a->rx)//직선
		return a->ry * b->rx < b->ry * a->rx;
	if (a->ry != b->ry)
		return a->ry < b->ry;
	return a->rx < b->rx;
}
ll dist(point* a, point* b) {
	return pow( a->x - b->x, 2) + pow(a->y - b->y, 2);
}
int main() {
	//input
	int N;
	scanf("%d", &N);
	vector<point*> arr(N);
	for (int i = 0; i < N; i++) {
		int a, b;
		scanf("%d%d", &a,&b);
		arr[i] = new point(a, b);
	}

	int midx = 0;
	for (int i = 1; i < N; i++)
		if (down(arr[i], arr[midx]))
			midx = i;
	swap(arr[0], arr[midx]);

	for (int i = 1; i < N; i++)
		arr[i]->set(arr[0]->x, arr[0]->y);
	sort(arr.begin()+1, arr.end(), cmp);

	stack<point*> s;
	s.push(arr[0]);
	point* first = s.top();
	point* second = arr[1];
	int i = 2;
	while (i < N) {
		while (i<N&&!s.empty()) {
			int CCW = ccw(first, second, arr[i]);
			if (CCW == 0) {
				if (dist(first, second) < dist(first, arr[i])) {
					second = arr[i];
				}
				i++;
				continue;
			}
			if (CCW > 0) {
				s.push(second);
				first = s.top();
				break;
			}
			else {
				second = s.top();
				s.pop();
				first = s.top();
			}
		}
		if (i<N) second = arr[i++];
	}
	int ans = s.size() + 1;
	printf("%d\n", ans);
}