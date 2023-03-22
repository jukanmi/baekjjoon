#include <bits/stdc++.h>
#define FIO\
	ios_base::sync_with_stdio(0);\
	cin.tie(0); cout.tie(0);
using namespace std;
#define endl "\n"
typedef long long ll;
int N;
vector<pair<int,int> > arr;
vector<int> location, s;
int len = 1;
int main() {
	FIO;
	//입력
	cin >> N;
	arr.resize(N);
	location.resize(N);
	s.resize(N);
	for (int i = 0; i < N; i++)
		cin >> arr[i].first >> arr[i].second;

	//사전작업
	sort(arr.begin(), arr.end());
	s[0] = arr[0].second;

	for (int i = 1; i < N; i++) {
		if (s[len - 1] < arr[i].second) {
			s[len++] = arr[i].second;
			location[i] = len - 1;
			continue;
		}
		int l = 0, r = len - 1;
		while (l < r) {
			int m = (l + r) / 2;
			if (s[m] < arr[i].second) l = m + 1;
			else r = m;
		}
		s[l] = arr[i].second;
		location[i] = l;
	}
	vector<int> ans;
	int mx = *max_element(location.begin(), location.end());
	for (int i = N-1; i >=0; i--) {
		if (location[i] != mx)ans.push_back(arr[i].first);
		else mx--;
	}
	reverse(ans.begin(), ans.end());
	cout << ans.size() << endl;
	for (int x : ans)
		cout << x << endl;
	return 0;
}