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
const int MAX = 1e3 + 1;
const int MAX_N = 1e7 + 1;
bool arr[101][101];
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	int N,M;
	cin>>N>>M;
	for (int i=0; i<N; i++)
		for (int j=0; j<M; j++) {
			char c;
			cin>>c;
			arr[i][j] = c=='1';
		}
	int ans=0;
	for (int i=N-1; i>=0; i--) {
		for (int j=M-1; j>=0; j--) {
			if (arr[i][j]) {
				for (int a=0; a<=i; a++)
					for (int b=0; b<=j; b++)
						arr[a][b]^=1;
				ans++;
			}
		}
	}
	cout << ans;
	return 0;
}
