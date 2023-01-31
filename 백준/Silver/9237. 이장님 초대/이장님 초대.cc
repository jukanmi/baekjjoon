#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
#define FIO ios_base::sync_with_stdio(0);cin.tie(0); cout.tie(0);
bool cmp(int a, int b) { return b < a; }
int main() {
    FIO;
    int N;
    cin >> N;
    vector<int> arr(N);
    for (int i = 0; i < N; i++)
        cin >> arr[i];
    sort(arr.begin(),arr.end(), cmp);
    int ans = 1;
    for (int i = 0; i < N; i++) {
        if (ans < arr[i] + 2 + i) ans = arr[i] + 2 + i;
    }
    cout << ans << endl;
}