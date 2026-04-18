#include <bits/stdc++.h>
using namespace std;
using ld = long double;
using ll = long long;
using vi = vector<int>;
using vvi = vector<vi>;
using ii = pair<int, int>;
using vii = vector<ii>;
using ll = long long;
using pll = pair<ll, ll>;
map<char, int> prior;
vector<char> convert = {'I', 'V', 'X', 'L', 'C', 'D', 'M'};
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

  prior['I'] = 1;
  prior['V'] = 5;
  prior['X'] = 10;
  prior['L'] = 50;
  prior['C'] = 100;
  prior['D'] = 500;
  prior['M'] = 1000;
}

int romaToArabia(string s) {
  int ans = 0;
  int cur = -1;
  char curc;
  for (auto &c : s) {
    if (cur == -1) {
      cur = prior[c];
      curc = c;
      continue;
    }
    if (c == curc) {
      cur += prior[c];
    } else if (prior[curc] > prior[c]) {
      ans += cur;
      cur = prior[c];
      curc = c;
    } else {
      ans += prior[c] - cur;
      cur = -1;
    }
  }
  if (cur != -1)
    ans += cur;
  return ans;
}

string arabiaToRoma(int s) {
  vvi matching = {{},  {0},    {0, 0},    {0, 0, 0},    {1, 0},
                  {1}, {0, 1}, {0, 0, 1}, {0, 0, 0, 1}, {2, 0}};
  string ans = "";
  int indx = 0;
  while (s) {
    int spl = s % 10;
    for (auto &c : matching[spl]) {
      ans = convert[c + indx] + ans;
    }
    s /= 10;
    indx += 2;
  }
  return ans;
}

int main() {
  init();
  int T;
  cin >> T;
  while (T--) {
    string s;
    cin >> s;
    try {
      int con = stoi(s);
      cout << arabiaToRoma(con);
    } catch (invalid_argument &e) {
      cout << romaToArabia(s);
    }

    cout << endl;
  }
  return 0;
}
