#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;
#define FIO ios_base::sync_with_stdio(0);cin.tie(0); cout.tie(0);
bool  cmp(int a, int b) {
    string a_str=to_string(a), b_str=to_string(b);
    int m=max(a_str.length(),b_str.length());
    int i;
    for (i=0; i<m; i++)
        if (a_str[i%a_str.length()]!=b_str[i%b_str.length()])
            break;
    return a_str[i%a_str.length()]>b_str[i%b_str.length()];
}
int main(){
    FIO;
    int N;
    cin >> N;
    vector<int> A(N);
    for (int i = 0; i < N; i++)
        cin >> A[i];
    sort(A.begin(), A.end(),cmp);
    if (A[0]==0){
        cout << 0 << endl;
        return 0;
    }
    for (int i = 0; i < N; i++)
        cout << A[i];
}