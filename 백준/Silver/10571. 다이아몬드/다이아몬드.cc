#include <bits/stdc++.h>
using namespace std;
using ld = long double;
using ll = long long;
using vi = vector<int>;
using vvi = vector<vi>;
using ii = pair<int, int>;
using vii = vector<ii>;
using ll = long long;
using pll = pair<ll, ll>;
void init(){
  ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cout << fixed;
    cout.precision(1);
  #ifndef BOJ
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w",stdout);
  #endif
}





int main() {
  init();
  int T;
  cin>>T;
  while (T--){
    int N;
    cin>>N;
    vector<pair<double,double>> dia(N);
    for (int i=0;i<N;i++)
      cin>>dia[i].first >> dia[i].second;
    vi dp(N,1);
    for (int i=1;i<N;i++){
      auto& [curw,curc] = dia[i];
      for (int j=i;j>=0;j--){
        auto& [w,c] = dia[j];
        if (curw>w && curc<c){
          dp[i] = max(dp[i],dp[j]+1);
        }
      }
    }
    int ans = 0;
    for (int i=0;i<N;i++){
      ans = max(ans,dp[i]);
    }
    cout << ans << endl;
  }
  


  
  return 0;
}
