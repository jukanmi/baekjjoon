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
int cnt;
ll dp[501][501];
int main()
{
  init();
  int N;
  cin>>N;
  int r,c;
  for (int i=0;i<501;i++)
    fill(dp[i],dp[i]+501,INF);
  vector<ll> arr(N+1);
  for (int i=0;i<N;i++){
    cin>>r>>c;
    arr[i] = r;
    dp[i][i] = 0;
  }
  arr[N] = c;
  
  for (int i=1; i<N; i++) {
    for (int j=0; j+i<N; j++) { 
      for (int k=j; k<j+i; k++) {
        dp[j][j+i] = min(dp[j][j+i], dp[j][k] + dp[k+1][j+i] + arr[j]*arr[k+1]*arr[j+i+1]);
      }
    }
  }
  cout<<dp[0][N-1]<<endl;
  return 0;
}