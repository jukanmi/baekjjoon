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

int main()
{
  init();
  int n, m;
  cin >> n >> m;
  vector<int> A,B;
  for (int i = 0; i < n; i++)
  {
    int tmp;
    cin >> tmp;
    A.push_back(tmp);
  }
  sort(A.begin(), A.end());
  for (int i = 0; i < m; i++)
  {
    int tmp;
    cin >> tmp;
    B.push_back(tmp);
  }
  sort(B.begin(),B.end());
  long long ans = 1;
  long long holeA = 1, holeB = 0;
  while (1)
  {

    while (holeB && !B.empty())
    {
      auto t = B.back();
      B.pop_back();
      holeB--;
      holeA += t;
    }
    ans = max(ans, holeA);
    if (A.empty())
      break;
    auto &b = A.back();
    A.pop_back();
    holeA--;
    holeB += b;
  }
  cout << ans;
  return 0;
}
