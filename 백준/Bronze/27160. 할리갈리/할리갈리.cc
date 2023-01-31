#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
using namespace std;
#define FIO ios_base::sync_with_stdio(0);cin.tie(0); cout.tie(0);
#define SWAP(x,y){int tmp=(x);(x)=(y);(y)=tmp;}
int main() {
    FIO;
    map <string,int> card={make_pair("BANANA",0),make_pair("STRAWBERRY",0),make_pair("LIME",0),make_pair("PLUM",0)};
    string s;
    int n,tmp;
    cin >> n;
    while (n--){
        cin >> s >> tmp;
        card[s]+=tmp;
    }
    for (pair<string,int> p : card){
        if (p.second == 5){
            cout << "YES" <<endl;
            return 0;
        }
    }
    cout << "NO" <<endl;
}