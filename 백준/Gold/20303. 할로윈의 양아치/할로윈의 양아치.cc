#include <bits/stdc++.h>
using namespace std;
#define FIO ios_base::sync_with_stdio(0);cin.tie(0); cout.tie(0);
int N, M, K;
map<int, vector<int>> relate;
vector<int> candy;
vector<int> v;
int dp[3001];
void dfs(int N, int color) {
    v[N] = color;
    for (int s : relate[N]) {
        if (!v[s])
            dfs(s, color);
    }
}

int main() {
    FIO;
    cin >> N >> M >> K;
    candy.resize(N+1);
    for (int i = 1; i <= N; i++)
        cin >> candy[i];
    for (int i = 1; i <= N; i++)
        relate[i] = vector<int>();
    for (int i = 0; i < M; i++) {
        int a, b;
        cin >> a >> b;
        relate[a].push_back(b);
        relate[b].push_back(a);
    }
    int color = 1;
    v.resize(N + 1,0);
    for (int i = 1; i <= N; i++) {
        if (!v[i])
            dfs(i, color++);
    }
    vector<pair<int,int>> group(color, make_pair(0,0));
    for (int i = 1; i <= N; i++) {
        group[v[i]].first++;
        group[v[i]].second += candy[i];
    }
    for (int i = 1; i < color; i++) {
        for (int j = K-1; j >=group[i].first; j--) {
            dp[j] = max(dp[j], dp[j - group[i].first] + group[i].second);
        }
    }
    cout << dp[K-1] << "\n";
}