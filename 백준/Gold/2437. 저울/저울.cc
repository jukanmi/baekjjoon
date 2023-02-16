#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int main(){
    ios_base::sync_with_stdio(0);cin.tie(0); cout.tie(0);
    int N;
    cin >> N;
    vector<int> A(N);
    for (int i = 0; i < N;i++)
        cin >> A[i];
    sort(A.begin(), A.end());
    int make=0;
    for (int i=0;i<N;i++){
        if (make+1<A[i])break;
        make+=A[i];
    }
    cout << make+1 << endl;
}