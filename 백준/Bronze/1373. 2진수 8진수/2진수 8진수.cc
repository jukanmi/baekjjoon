#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#define endl "\n"
#define FIO\
	ios_base::sync_with_stdio(0);\
	cin.tie(0); cout.tie(0);
using namespace std;
typedef long long ll;

int main(){
	FIO;
	vector<int> ans;
	string num;
	cin >> num;
	if (num=="0"){
		cout << 0;
		return 0;
	}
	reverse(num.begin(), num.end());
	int sum=0;
	for (int i=0; i<num.size();i++){
		sum+=(num[i]-'0')*pow(2,i%3);
		if (i%3==2){
			ans.push_back(sum);
			sum=0;
		}
	}
	if (sum)
		ans.push_back(sum);
	reverse(ans.begin(), ans.end());
	for (int i:ans)
		cout << i;
}