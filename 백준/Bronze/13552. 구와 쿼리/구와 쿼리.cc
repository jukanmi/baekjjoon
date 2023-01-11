#include <iostream>
#define endl "\n"
using namespace std;
typedef long long ll;
int main() {
	ios_base::sync_with_stdio(0);cin.tie(0); cout.tie(0);
	int N;
	cin >> N;
	int point[100000][3];
	for (int i=0; i<N; i++)
		cin >> point[i][0] >> point[i][1] >> point[i][2];
	int M,x,y,z,r;
	cin >> M;
	while (M--){
		cin >> x >> y >> z >> r;
		int ans=0;
		for (int i=0; i<N; i++)
			if ((ll)(point[i][0]-x)*(point[i][0]-x)+(ll)(point[i][1]-y)*(point[i][1]-y)+(ll)(point[i][2]-z)*(point[i][2]-z)<=(ll)r*r)
				ans++;
		cout << ans << endl;
	}
}