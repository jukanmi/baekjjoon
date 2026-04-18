#include <bits/stdc++.h>
using namespace std;
using ld = long double;
using ll = long long;
using vi = vector<int>;
using vvi = vector<vi>;
using ii = pair<int, int>;
using vii = vector<ii>;
using ll = long long;
using pll = pair<ll, ll>;
#define endl "\n"
#define all(x) x.begin(), x.end()
const int MAX = 1e5 + 1;
ll N;
ll A[MAX],B[MAX],X[MAX];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cin>>N;
	for (int i=0; i<N; i++)
		cin>>A[i];
	for (int i=0; i<N; i++)
		cin>>B[i];
	for (int i=0; i<N; i++)
		cin>>X[i];
	ll ans = 0;

	ll setting = abs(B[0]-A[0])/X[0];
	for (int i=0; i<N; i++) {
		ll curr = abs(B[i]-A[i])/X[i];
		if ((abs(B[i]-A[i])%X[i])||(curr%2 !=setting%2)) {
			ans=-1;
			break;
		}
		if (setting <curr)
			setting = curr;
	}
	if (ans !=-1)
		ans = abs(setting);
	cout << ans;
	return 0;
}
