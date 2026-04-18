#include <bits/stdc++.h>
#include <limits>
using namespace std;
#define FIO                                                                    \
  ios_base::sync_with_stdio(0);                                                \
  cin.tie(0);                                                                  \
  cout.tie(0);
#define all(x) x.begin(), x.end()
using ld = long double;
using ll = long long;
using pdd = pair<double, double>;
using pii = pair<int, int>;
using vi = vector<int>;
bool prime[2002]; //소수가 아닌가?
bool match[51];
int matched[51];
int arr[51];
int N;
// cur을 빌릴수있는가?
bool dfs(int cur, vi &evens, vi &odds) {
  for (int i = 0; i < odds.size(); i++) { //이동가능간선
    if (prime[evens[cur] + odds[i]] || match[i])
      continue;
    match[i] = 1;
    if (matched[i] == -1 || dfs(matched[i], evens, odds)) {
      matched[i] = cur;
      return 1;
    }
  }
  return 0;
}
void init() {
  for (int i = 0; i < 51; i++) {
    match[i] = 0;
    matched[i] = -1;
  }
}
int main() {
  FIO;
  //freopen("input.txt", "r", stdin);
  for (int i = 2; i < 2002; i++) {
    if (!prime[i])
      for (int j = i + i; j < 2002; j += i) {
        prime[j] = 1;
      }
  }
  cin >> N;
  for (int i = 1; i <= N; i++) {
    cin >> arr[i];
  }
  vector<int> ans;
  for (int A = 2; A <= N; A++) {
    if (prime[arr[1] + arr[A]])
      continue;
    vi evens, odds;
    init();
    evens.clear(), odds.clear();
    
    for (int z = 1; z <= N; z++) {
      if (arr[z] == arr[1] || arr[z] == arr[A])
        continue;
      else if (arr[z] & 1)
        odds.push_back(arr[z]);
      else
        evens.push_back(arr[z]);
    }
    if (evens.size() != odds.size())
      continue;
    int matchings = 0;
    for (int i = 0; i < evens.size(); i++) {
      fill(match,match+51,0);
      matchings += dfs(i, evens, odds);
    }
    if (matchings == evens.size())
      ans.push_back(arr[A]);
/*
    for (auto &even : evens)
      cout << even << " ";
    cout << endl;
    for (auto &odd : odds)
      cout << odd << " ";
    cout << endl;
    for (int i = 0; i < evens.size(); i++)
      cout << matched[i] << " ";
    cout << endl;
    cout << "matching:" << matchings << endl;
    */
  }
  if (ans.empty()) {
    cout << -1;
    return 0;
  }
  sort(all(ans));
  for (auto &an : ans) {
    cout << an << " ";
  }
}
