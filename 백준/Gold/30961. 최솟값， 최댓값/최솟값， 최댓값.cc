#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int N;
    cin >> N;
    vector<long long> arr(N);
    for (int i = 0; i < N; i++) {
        cin >> arr[i];
    }
    sort(arr.begin(), arr.end());
    long long ans = arr[0] * arr[0];
    for (int i = 1; i < N; i++) {
        ans ^= arr[i] * arr[i];
        ans ^= arr[i - 1] * arr[i];
    }
    cout << ans;
}