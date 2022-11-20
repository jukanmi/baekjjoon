#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#define endl "\n"
#define FIO ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
typedef long long ll;

int main() {
	FIO
	int N;
	cin >> N;
	vector<pair<int, int> > stra(N);
	for (int i=0; i<N; i++){
		cin >> stra[i].first >> stra[i].second;
		if (stra[i].first>stra[i].second){
			int tmp=stra[i].first;
			stra[i].first=stra[i].second;
			stra[i].second=tmp;
		}
	}
	sort(stra.begin(),stra.end());
	int ans=0,start=stra[0].first,forward=stra[0].second;
	for (int i=1; i<N; i++){
		if (forward<=stra[i].first){
			ans+=forward-start;
			start=stra[i].first;
			forward=stra[i].second;
		}
		else if (forward<stra[i].second){
			forward=stra[i].second;
		}
	}
	ans+=forward-start;
	cout << ans;
	return 0;
}