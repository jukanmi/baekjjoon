#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#define MAX 2147483647
#define base\
	ios_base::sync_with_stdio(0);\
	cin.tie(0); cout.tie(0);
using namespace std;

bool cmp(vector<int>& v1, vector<int>& v2) {
	if (v1[0] == v2[0])
		return v1[1] > v2[1];
	else return v1[0] < v2[0];
}

int main() {
	base;
	int N, B, a, b, fri = 0, A;
	long long spend = 0;
	cin >> N >> B;
	vector<vector<int> > V(N,vector<int>(2,0));
	for (int i = 0; i < N; i++) {
		cin >> a >> b;
		V[i][0] = a + b;
		V[i][1] = a;
	}

	sort(V.begin(), V.end(), cmp);
	for (A = 0; A < N; A++) {
		if (spend + V[A][0] > B) break;
		spend += V[A][0];
		fri++;
	}
	int max = 0;
	for (int i = 0; i <= A; i++) {
		max = max < V[i][1] ? V[i][1] : max;
	}
	spend -= max / 2;
	for (int i = A; i < N; i++) {
		if (spend + V[i][0] > B) break;
		spend += V[i][0];
		fri++;
	}
	printf("%d", fri);
}