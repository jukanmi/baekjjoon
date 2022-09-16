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
	int N, M;
	cin >> N >> M;
	deque<int> q;
	int INF[230000];
	fill(INF, INF + 222222, MAX);
	q.push_front(N);
	INF[N] = 0;
	while (!q.empty()) {
		int temp = q.front();
		q.pop_front();
		if (temp == M) {
			cout << INF[M];
			return 0;
		}
		int tem = temp * 2;
		if (tem <= 200000 && INF[tem] > INF[temp]) {
			INF[tem] = INF[temp];
			q.push_front(tem);
		}
		if (temp - 1 >= 0 && INF[temp - 1] > INF[temp] + 1) {
			q.push_back(temp - 1);
			INF[temp - 1] = INF[temp] + 1;
		}
		if (temp + 1 <= 200000 && INF[temp + 1] > INF[temp] + 1) {
			q.push_back(temp + 1);
			INF[temp + 1] = INF[temp] + 1;
		}
	}
}