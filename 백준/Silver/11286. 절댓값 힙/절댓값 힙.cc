#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#define MAX 2147483647
#define base\
	ios_base::sync_with_stdio(0);\
	cin.tie(0); cout.tie(0);
using namespace std;

int main() {
	base;
	priority_queue<int, vector<int>, greater<int>> p, m;
	int n, tmp, P = 0, M = 0;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> tmp;
		if (tmp) {
			if (tmp > 0) {
				p.push(tmp);
				P++;
			}
			else {
				m.push(-tmp);
				M++;
			}
		}
		else {
			if (!P || !M) {
				if (!P && !M) cout << "0" << "\n";
				else if (!P) { cout << -m.top() << "\n"; m.pop(); M--; }
				else { cout << p.top() << "\n"; p.pop(); P--; }
			}
			else {
				if (p.top() < m.top()) {
					cout << p.top() << "\n";
					p.pop();
					P--;
				}
				else {
					cout << -m.top() << "\n";
					m.pop();
					M--;
				}
			}
		}
	}
}