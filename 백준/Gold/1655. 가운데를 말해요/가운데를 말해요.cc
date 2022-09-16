#include <iostream>
#include <queue>
#define base\
	ios_base::sync_with_stdio(0);\
	cin.tie(0); cout.tie(0);
using namespace std;
int main() {
	base;
	int n, temp;
	int xqlen = 0, nqlen = 0;
	priority_queue<int, vector<int>,less<int>>max_queue;
	priority_queue<int, vector<int>, greater<int>> min_queue;
	cin >> n;
	while (n--) {
		cin >> temp;
		if (xqlen > nqlen) {
			min_queue.push(temp);
			nqlen++;
		}
		else {
			max_queue.push(temp);
			xqlen++;
		}
		while (nqlen&&xqlen&&min_queue.top() < max_queue.top()) {
			int min = min_queue.top(), max = max_queue.top();
			max_queue.pop();
			max_queue.push(min);
			min_queue.pop();
			min_queue.push(max);
		}
		cout << max_queue.top() << "\n";
	}
}