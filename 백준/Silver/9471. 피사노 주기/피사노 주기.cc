#include <iostream>
#include <vector>
#include <algorithm>
#define MAX 21474836
#define base\
	ios_base::sync_with_stdio(0);\
	cin.tie(0); cout.tie(0);
using namespace std;
int main(){
	int t,tmp,ans[1000];
	vector<int> v;
	cin >> t;
	for (int i=1;i<=t;i++){
		int len=2,non;
		v.clear();
		v.push_back(0);v.push_back(1);//초기값 세팅
		cin >> tmp;
		cin >> tmp;
		for (int j=0;j<500000;j++){
			v.push_back((v[len-1]+v[len-2])%tmp);
			len++;
			if (v[len-1]==1&&v[len-2]==0){
				break;
			}
		}
		cout << i << ' ' << len-2 << '\n';
	}
}