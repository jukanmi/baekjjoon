#include <iostream>
#include <queue>
using namespace std;
int T;
priority_queue <std::pair <int, std::pair <int, int>>> Q;

void Input() {
	int N;
	cin >> T >> N;
	for (int i = 0; i < N; i++) {
		int A, B, C;
		cin >> A >> B >> C;
		Q.push({ C, {-A, B} });
	}
}

void Solve() {
	while (T && !Q.empty()) {
		int C = Q.top().first;
		int A = Q.top().second.first;
		int B = Q.top().second.second;
		Q.pop();
		cout << -A << "\n";
		C--;
		B--;
		if (B != 0) Q.push({ C,{A,B} });
		T--;
	}
}

int main() {
	Input();
	Solve();
}