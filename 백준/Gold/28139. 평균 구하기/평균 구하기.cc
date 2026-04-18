#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define endl "\n"
void init()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cout.precision(9);
  cout<<fixed;
#ifndef BOJ
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
#endif
}
long double dist(pair<int,int>& a, pair<int,int>& b){
  return sqrtl((a.first-b.first)*(a.first-b.first)  + (a.second-b.second)*(a.second-b.second));
}
int main()
{
  init();
  long double ans=0;
  int N;
  cin>>N;
  vector<pair<int,int>> A(N);
  for (int i=0;i<N;i++){
    cin>>A[i].first >> A[i].second;
  }
  for (int i=0;i<N;i++){
    for (int j=0;j<N;j++){
      if (i==j) continue;
        ans+=dist(A[i],A[j]);
    }
  }
  cout << ans/N;
  return 0;
}
