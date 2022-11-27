#include <iostream>
#include <queue>
#include <vector>
#include <map>
#include <string>
#include <algorithm>
#define FIO\
	ios_base::sync_with_stdio(0);\
	cin.tie(0); cout.tie(0);
using namespace std;
#define endl "\n"
int main(){
	FIO
    int N;
    cin >> N;
    vector<int> arr(N);
    for (int i=0;i<N;i++)
        cin >> arr[i];
    int M;
    cin >> M;
    sort(&arr[0],&arr[N]);
    int p1=0,p2=N-1,ans=0;
    while (1){
      if (p1>=p2)
        break;
      int sum=arr[p1]+arr[p2];
      if (sum==M){
        ans++;
        p1++;
        p2--;
      }
      else if (sum<M)
        p1++;
      else 
        p2--;
    }
    cout << ans;
}