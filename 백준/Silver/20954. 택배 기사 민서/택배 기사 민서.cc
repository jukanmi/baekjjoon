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
  int T;
  cin >> T;
  while (T--)
  {
    ll x;
    cin >> x;
    ll ans = 0;
    ll k = 0;
    if (x > 0)
    {
      k = log2(x);
      ans += x;
    }
    else if (x < 0)
    {
      k = log2(-x);
      if (abs(x) == (1 << k))
      k--;
      ans += -x + (1LL << (k + 1)) * 2;
    }
    else
    {
      cout << "0\n";
      continue;
    }
    if (abs(x) != (1 << k))
      k++;
    ans += 4 * ((1LL << k) - 1);
    cout << ans << endl;
  }
  return 0;
}
