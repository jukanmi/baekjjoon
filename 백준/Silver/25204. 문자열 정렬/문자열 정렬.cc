#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define endl "\n"
void init()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0); /*
   cout.precision(9);
   cout<<fixed;
   /**/
#ifndef BOJ
  freopen("input.txt", "r", stdin);
  // freopen("output.txt", "w", stdout);
#endif
}
bool cmp(const string &a, const string &b)
{
  if (a == b)
    return true;
  if (a.size() > b.size() && a.substr(0, b.size()) == b)
    return false;
  if (a.size() < b.size() && b.substr(0, a.size()) == a)
    return true;
  int s = min(a.size(), b.size());
  for (int i = 0; i < s; i++)
  {
    if (a[i] == b[i])
      continue;
    if (a[i] == '-' || b[i] == '-')
      return b[i] == '-';
    if (tolower(a[i]) == tolower(b[i]))
      return ('a' <= b[i] && b[i] <= 'z');
    return (tolower(a[i]) < tolower(b[i]));
  }
}
int main()
{
  init();
  int T;
  cin >> T;
  while (T--)
  {
    int N;
    cin >> N;
    vector<string> s(N);
    for (int i = 0; i < N; i++)
      cin >> s[i];
    sort(s.begin(), s.end(), cmp);
    for (auto &c : s)
      cout << c << endl;
  }
  return 0;
}
