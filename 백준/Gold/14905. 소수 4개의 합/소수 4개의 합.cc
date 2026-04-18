#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define endl "\n"
void init()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cout << fixed;
  // cout.precision(1);
#ifndef BOJ
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
#endif
}

const int N = 1e8;
bitset<N + 1> prime;
void mkPrimeVec()
{
  prime.set();
  prime[0] = prime[1] = 0;
  for (int i = 2; i <= (int)sqrt(N); i++)
  {
    if (prime[i])
      for (int j = i * i; j <= N; j += i)
        prime[j] = 0;
  }
}
int main()
{
  init();
  mkPrimeVec();
  int n;
  while (cin >> n)
  {
    if (n<8){
      cout <<  "Impossible." << endl;
      continue;
    }
    if (n & 1)
    {
      int tmp = n - 5;
      for (int i = 2; i <= tmp / 2; i++)
        if (prime[i] && prime[tmp - i])
        {
          cout << "2 3 " << i << " " << tmp - i << endl;
          break;
        }
    }
    else
    {
      int tmp = n - 4;
      for (int i = 2; i <= tmp / 2; i++)
        if (prime[i] && prime[tmp - i])
        {
          cout << "2 2 " << i << " " << tmp - i << endl;
          break;
        }
    }
  }
  return 0;
}
