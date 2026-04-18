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

int fri[1001][1001];
int main()
{
  init();
  int N,M;
  cin>>N>>M;
  for (int i=0;i<M;i++)
    for (int j=0;j<N;j++)
      cin>>fri[i][j];
  cout << M << endl;
  for (int i=0;i<M;i++){
    int tmp=0;
    for (int j=0;j<N;j++){
      cout << fri[(i+tmp)%M][j] << " ";
      tmp++;
    }
    cout << endl;
  }
  return 0;
}
