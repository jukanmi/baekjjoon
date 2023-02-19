#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
#define FIO ios_base::sync_with_stdio(0);cin.tie(0); cout.tie(0);
int N, M, A, B;
vector<int> ans, dp;
vector<vector<int>> re;
void func(int i, int cnt) {
    ans[i] = max(ans[i], cnt);
    if (!dp[i]) {
        cnt = ans[i];
        for (int j : re[i]) {
            dp[j]--;
            func(j, cnt + 1);
        }
    }
}
int main() {
    FIO;
    cin >> N >> M;
    ans.resize(N + 1, 0);
    re.resize(N + 1);
    dp.resize(N + 1);
    for (int i = 0; i < M; i++) {
        cin >> A >> B;
        re[A].push_back(B);
        dp[B]++;
    }
    for (int i = 1; i <= N; i++)
        if (!dp[i] && !ans[i])
            func(i, 1);
    for (int i = 1; i <= N; i++)
        cout << ans[i] << " ";
    cout << endl;
}