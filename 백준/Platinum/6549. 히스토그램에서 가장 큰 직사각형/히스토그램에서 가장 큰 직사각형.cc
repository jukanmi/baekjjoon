#include <iostream>
#include <stack>
using namespace std;
typedef long long ll;

int main() {
	//freopen("input.txt", "r", stdin);
	stack<int> stck;
	while (1){
		int N;
		scanf("%d", &N);
		if (!N)break;
		ll max=0;
		int arr[100000];
		for (int i = 0; i < N; i++)
			scanf("%d",&arr[i]);
		for (int i=0;i<N;i++){
			while (!stck.empty()&&arr[stck.top()]>arr[i]){
				ll high=arr[stck.top()];
				stck.pop();
				ll wid=i;
				if (!stck.empty()) 
					wid-=stck.top()+1;
				max=max<wid*high?wid*high:max;
			}
			stck.push(i);
		}
		while (!stck.empty()){
			ll high=arr[stck.top()];
			ll wid=N;
			stck.pop();
			if (!stck.empty()) 
				wid-=stck.top()+1;
			max=max<wid*high?wid*high:max;
		}
		cout << max << "\n";
	}
}
