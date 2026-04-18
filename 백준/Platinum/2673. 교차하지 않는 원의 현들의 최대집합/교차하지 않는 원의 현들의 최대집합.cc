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
#endif
}

int N;
int exists[101][101];
int dp[101][101];


int main()
{
  init();
  cin >> N;
  for (int i = 0; i < N; i++)
  {
    int a,b;
    cin >> a >> b;
    exists[a][b] = exists[b][a] = 1;
  }
  for (int j=1;j<=100;j++){
    for (int i=j-1;i>=1;i--){
      for (int k=i;k<j;k++){
        dp[i][j] = max(dp[i][j], dp[i][k] + dp[k][j] + exists[i][j]);
      }
    }
  }
  cout << dp[1][100] << endl;
  return 0;
}
