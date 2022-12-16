
#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
#define endl "\n"
using namespace std;
#define FIO\
	ios_base::sync_with_stdio(0);\
	cin.tie(0); cout.tie(0);
vector<int> rout[200001];
stack<int> s;
int SCC[200001];
int visit[200001];
int SCClen,Verlen=1;
int scc(int curr);
int main() {
	FIO
	//freopen("input.txt", "r", stdin);
	int N,M;
	cin >> N >> M;
	for (int i = 0; i < M; i++) {
		int A, B;
		cin >> A >> B;
		for (int j = 0; j < rout[A].size(); j++)
			if (rout[A][j] == B)
				continue;
		rout[A].push_back(B);
	}
	for (int i = 1; i <= N; i++) {
		SCC[i] = -1;
		visit[i] = -1;
	}
	scc(1);
	for (int i = 1; i <= N; i++) {
		if (SCC[i] == -1) {
			cout << "No";
			return 0;
		}
	}
	if (SCClen >= 2)
		cout << "No";
	else
		cout << "Yes";
	return 0;
}
int scc(int curr) {
	int ret = visit[curr] = Verlen++;
	s.push(curr);
	for (int i = 0; i < rout[curr].size(); i++) {
		int next = rout[curr][i];
		int tmp;
		if (visit[next]==-1)
			ret = min(ret, scc(next));
		else if (SCC[next] == -1)
			ret = min(ret, visit[next]);
	}
	if (ret == visit[curr]) {
		while (1) {
			int temp = s.top();
			s.pop();
			SCC[temp] = SCClen;
			if (temp == curr) break;
		}
		SCClen++;
	}
	return ret;
}