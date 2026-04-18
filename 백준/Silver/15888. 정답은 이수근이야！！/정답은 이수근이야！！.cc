#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int MOD = 100;
void init() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cout.precision(10);
  cout << fixed;
}
bool isdigitz(double a){
	return abs((int)a - a)<1e-7;
}
int main() {
  init();
  double a,b,c;
  cin>>a>>b>>c;
  double x = (-b+sqrt(b*b-4*a*c))/(2*a), y = (-b-sqrt(b*b-4*a*c))/(2*a);
  if (x!=y && isdigitz(log2(x)) && isdigitz(log2(y)) && log2(x)>0 && log2(y) >0)
	cout << "이수근";
  else if (isdigitz(x) && isdigitz(y) && x!=y)
	cout << "정수근";
  else
	cout << "둘다틀렸근";
}
