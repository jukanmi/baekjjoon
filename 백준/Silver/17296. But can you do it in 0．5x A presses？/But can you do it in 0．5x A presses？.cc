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
  int N;
  cin >> N;
  int ans = 0;
  bool p = 0;
  for (int i = 0; i < N; i++)
  {
    double tmp;
    cin >> tmp;
    if (tmp!=0 && !p){
      p=1;
      ans++;
      tmp-=0.5;
    }
    ans+=(int)tmp;
  }
  cout << ans;
  return 0;
}
