#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
#define FIO ios_base::sync_with_stdio(0);cin.tie(0); cout.tie(0);
int T;
string str;
int main(){
    FIO;
    cin >> T;
    while (T--){
        cin >> str;
        int s=0,e=str.length()-1;
        while (s<e){
            if (str[s]==str[e])
                s++,e--;
            else
                break;
        }
        if (s>=e){puts("0");continue;}
        int a=s+1,b=e;
        while(a<b){
            if (str[a]==str[b])
                a++,b--;
            else
                break;
        }
        if (a>=b){puts("1");continue;}
        a=s,b=e-1;
        while(a<b){
            if (str[a]==str[b])
                a++,b--;
            else
                break;
        }
        if (a>=b){puts("1");continue;}
        puts("2");
    }
}