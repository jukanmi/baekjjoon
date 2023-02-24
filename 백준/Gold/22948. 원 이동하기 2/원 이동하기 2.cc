#include <bits/stdc++.h>
using namespace std;
#define FIO ios_base::sync_with_stdio(0);cin.tie(0); cout.tie(0);
class circle {
public:
	int idx,start,end;
	circle(int i, int s, int e) { idx = i; start = s; end = e; }
};
bool cmp(circle* a, circle* b) {
	return a->start < b->start;
}
int main() {
	FIO;
	int N;
	cin >> N;
	vector<circle*> circles(N+1);
	circles[0] = new circle(0, -1000001, 1000001);
	for (int i = 1; i <= N; i++) {
		int a, x,r;
		cin >> a >> x >> r;
		circles[i] = new circle(a, x - r, x + r);
	}
	int A, B;
	cin >> A >> B;
	sort(circles.begin(), circles.end(), cmp);
	stack<circle*> ss;
	bool index[200001] = { 0 };
	int start = -1,end=-1;
	vector<int> ans;
	for (circle* c : circles) {
		if (c->idx == A || c->idx == B) {
			if (start == -1) {
				start = c->idx;
			}
			else {
				end = c->idx;
			}
		}
		while (!ss.empty() && ss.top()->end < c->start) {
			if (start!=-1&&!ans.empty()&&index[ans[ans.size()-1]])
				ans.pop_back();
			ss.pop();
			if (start != -1 && !ans.empty() && ans[ans.size() - 1] != ss.top()->idx)
				ans.push_back(ss.top()->idx);
		}
		ss.push(c);
		if (start != -1) {
			if (c->idx != start)
				index[c->idx] = true;
			ans.push_back(c->idx);
		}
		if (end!=-1)break;
	}
	cout << ans.size() << endl;
	if (ans[0] != A)
		reverse(ans.begin(), ans.end());
	for (int i : ans)
		cout << i << " ";
}