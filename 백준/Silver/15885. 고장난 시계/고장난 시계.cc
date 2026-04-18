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
  double a,b;
  cin>>a>>b;
  cout << int(2*abs((a/b-1)));
  return 0;
}
