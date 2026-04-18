#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define endl "\n"

const int INF = 987654321;
void init()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
}

set<int> num;
int n;
void func(int cnt){
  if (cnt>=n) return;
  vector<int> v;
  for (auto& x:num) v.push_back(x);
  for (int i=1;i<=9;i++){
    for (auto& x:v){
     num.insert(x*i);
    }
  }
  func(cnt+1);
}
int main()
{
  init();
  cin>>n;
  num.insert(1);
  func(0);
  cout << num.size() << endl;
  return 0;
}
