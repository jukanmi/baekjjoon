#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;
#define endl "\n"
#define FIO ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
typedef long long ll;



int main() {
	FIO
		int max = INT_MIN;
	string kkr;
	cin >> kkr;
	vector<int> sum(kkr.size() + 1, 0);// 누적합
	int len = kkr.size();
	for (int i = 0; i < len; i++) {
		if (kkr[i] == 'R')
			sum[i + 1] = sum[i] + 1;
		else
			sum[i + 1] = sum[i];
	}
	int l = 0, r = len - 1;
	while (l <= r) {
		if (l - sum[l] < len - 1 - r - sum[len] + sum[r + 1])
			l++;
		else if (l - sum[l] > len - 1 - r - sum[len] + sum[r + 1])
			r--;
		else l++, r--;
			
		if (sum[r+1] - sum[l] == 0) continue;
		max = max < 2 * min(l - sum[l], len-1 - r - sum[len] + sum[r+1]) + sum[r+1] - sum[l] ? 2 * min(l - sum[l], len -1- r - sum[len] + sum[r+1]) + sum[r+1] - sum[l] : max;
	}
	max = max < sum[len] ? sum[len] : max;
	cout << max;
}