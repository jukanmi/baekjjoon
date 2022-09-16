#include <iostream>
#include <queue>
#include <vector>
#define base\
	ios_base::sync_with_stdio(0);\
	cin.tie(0); cout.tie(0);
using namespace std;
int main() {
    base;
    priority_queue<int,vector<int>,greater<int>> Q;
    int N,temp,ans=0;
    cin>>N;
    for (int i=0; i<N; i++) {
        cin>>temp;
        Q.push(temp);
    }
    while (Q.size() > 1) {
        int a=Q.top();Q.pop();
        int b=Q.top();Q.pop();
        ans+=a+b;
        Q.push(a+b);
    }
    cout<<ans<<"\n";
}