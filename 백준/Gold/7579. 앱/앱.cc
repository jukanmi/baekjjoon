#include <bits/stdc++.h>
using namespace std;
#define FIO ios_base::sync_with_stdio(0);cin.tie(0); cout.tie(0);

int N, M;
int bag[10000001];
int arr[101][2];
int main() {
	FIO;
	cin >> N >> M;
	fill(bag, bag + M + 1, 2e9);
	bag[0] = 0;
	for (int i = 0; i < N; i++)
		cin >> arr[i][0];
	for (int i = 0; i < N; i++)
		cin >> arr[i][1];
	int ans = INT_MAX;
	for (int app = 0; app < N; app++) {
		for (int i = M; i >= 0; i--) {
			if (i+arr[app][0]>=M&&ans>bag[i]+arr[app][1])
				ans = bag[i] + arr[app][1];
			if (i>=arr[app][0]) bag[i] = min(bag[i], bag[i - arr[app][0]] + arr[app][1]);
		}
	}
	cout << ans << endl;
}