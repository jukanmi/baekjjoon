#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#define MOD 1000000007
#define endl "\n"
using namespace std;
typedef long long ll;
#define endl "\n"
#define FIO\
	ios_base::sync_with_stdio(0);\
	cin.tie(0); cout.tie(0);
int main(){
    FIO
    int N,M;
    string str;
    map<string, bool> hasmap;
    cin >> N >> M;
    while (N--){
        cin >> str;
        hasmap[str]=true;
    }
    int ans=0;
    while (M--){
        cin >> str;
        if (hasmap[str])
            ans++;
    }
    cout << ans << endl;
    return 0;
}