#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;
#define endl "\n"
#define FIO ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
typedef long long ll;



int main() {
	//freopen("input.txt", "r", stdin);
	int N;
	cin >> N;
	vector<int> start(N);
	vector<int> end(N);
	int ans[3] = { 0 };
	int S = 0, E = 0, mogi = 0, first;
	for (int i = 0; i < N; i++)
		cin >> start[i] >> end[i];
	sort(start.begin(), start.end());
	start.push_back(INT_MAX);
	sort(end.begin(), end.end());
	for (int i = 0; i < 2 * N; i++) {
		if (start[S] < end[E]) {
			first = start[S++];
			mogi++;
		}
		else if (start[S] > end[E]) {
			if (ans[0] < mogi) {
				ans[0] = mogi;
				ans[1] = first;
				ans[2] = end[E];
			}
			E++;
			mogi--;
		}
		else {
			S++;
			E++;
			i++;
		}
	}
	cout << ans[0] << endl << ans[1] << " " << ans[2];
}