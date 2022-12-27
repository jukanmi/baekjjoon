#include <iostream>
#include <deque>
#define endl "\n"
#define FIO\
	ios_base::sync_with_stdio(0);\
	cin.tie(0); cout.tie(0);
using namespace std;
typedef long long ll;

int main(){
	FIO;
	deque<int>ans;
	string num;
	cin >> num;
	if (num=="0"){
		cout << 0;
		return 0;
	}
	for (int i=0;i<num.length();i++){
		int x=num[i]-'0',y=4;
		while (y){
			if (x>=y){
				ans.push_back(1);
				x-=y;
			}
			else
				ans.push_back(0);
			y/=2;
		}
	}
	while (ans.front() ==0)
		ans.pop_front();
	for (int i:ans)
		cout << i;
}