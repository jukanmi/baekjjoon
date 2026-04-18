#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define endl "\n"

const int INF = 987654321;
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
#endif
}

int main()
{
  init();
  int n;
  cin >> n;
  int s, t;
  map<string, int> m;
  for (int i = 0; i < n; i++)
  {
    cin >> s >> t;
    for (int j = 0; j < t; j++)
    {
      string x;
      cin >> x;
      if (m.find(x) == m.end())
        m[x] = -1;
      else
        m[x]--;
    }
  }
  vector<pair<int, string>> v;
  for (auto &p : m)
    v.push_back({p.second, p.first});
  sort(v.begin(), v.end());
  if (v.size() >= 2 && v[0].first == v[1].first)
    cout << -1;
  else
    cout << v[0].second;
  return 0;
}
