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

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	int T;
	cin >>T;
	while (T--) {
		int N;
		cin>>N;
		int a,b;
		vii number(N);
		bool flag=1;
		for (int i=0; i<N; i++) {
			cin>>number[i].first>>number[i].second;
		}
		sort(all(number));
		vi init;
		int curx=number[0].first;
		int indx=0;
		for (int i =0; i<N; i++) {
			auto& [x,y] = number[i];
			if (x==number[0].first)
				init.push_back(y);
			else
			{
				if (curx!=x) {
					indx=0;
					curx = x;
				}
				if (indx>=init.size()||init[indx] != y)
					flag=0;
				indx++;
			}
		}

		cout << (flag?"BALANCED": "NOT BALANCED") << endl;
	}
	return 0;
}
