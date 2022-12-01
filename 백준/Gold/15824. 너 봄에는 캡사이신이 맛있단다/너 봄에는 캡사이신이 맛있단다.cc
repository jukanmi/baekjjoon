#include <iostream>
#include <vector>
#include <algorithm>
#define MOD 1000000007
using namespace std;
typedef long long ll;
#define endl "\n"
#define FIO\
	ios_base::sync_with_stdio(0);\
	cin.tie(0); cout.tie(0);
ll fastpow(ll num, int power) {
	if (power < 0) return 0;
	ll ans = 1;
	while (num<=(1<<30)&&power) {
		if (power % 2 == 1) {
			ans *= num;
			ans %= MOD;
		}
		num = num * num % MOD;
		power /= 2;
	}
	while (power--) {
		ans *= num;
		ans %= MOD;
	}
	return ans-1;
}
int main() {
	FIO
	int N;
	cin >> N;
	ll sum = 0;
	vector<int> menu(N);
	for (int i = 0; i < N; i++)
		cin >> menu[i];
	sort(menu.begin(), menu.end());
	for (int i = 1; i <= N; i++) {
		sum += (menu[i - 1] % MOD) * (fastpow(2, i - 1)%MOD - fastpow(2, N - i)%MOD+MOD)%MOD;
		sum %= MOD;
	}
	cout << sum << endl;
}