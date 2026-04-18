#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define endl "\n"

const ll INF = 2147483647;
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
};

int main()
{
  init();
  int T,n;
  cin >> T;
  while (T--)
  {
    cin >> n;
    long double ans = 0;
    for (int i = 1; i <= n; i++)
    {
      ans += log10l(i);
    }
    cout << (long long)(ans + 1) << endl;
  }
  return 0;
}