#include <bits/stdc++.h>
using namespace std;
using ll = long long;
void init() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cout << fixed;
  cout.precision(1);
#ifndef BOJ
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
#endif
}
vector<int> manacher(const string& s) {
    string t = "@";  // 시작 경계 문자
    for (char c : s) {
        t += "#";
        t += c;
    }
    t += "#$";  // 끝 경계 문자

    int n = t.size();
    vector<int> p(n, 0);  // p[i]는 i를 중심으로 한 팰린드롬 반지름
    int center = 0, right = 0;

    for (int i = 1; i < n - 1; ++i) {
        int mirror = 2 * center - i;
        if (i < right)
            p[i] = min(right - i, p[mirror]);

        while (t[i + (1 + p[i])] == t[i - (1 + p[i])])
            ++p[i];

        if (i + p[i] > right) {
            center = i;
            right = i + p[i];
        }
    }

    return p;
}

int main() {
  init();

  string s;
  cin >> s;
  auto r = manacher(s);
  int ans = 0;
  for (auto& c : r){
    ans = max(ans,c);
  }
  cout << ans;
  

  return 0;
}
