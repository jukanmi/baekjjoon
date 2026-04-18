#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define endl "\n"

const int INF = 987654321;
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
int N, M;
bool prime[9001];
int arr[11];
void sieve()
{
  fill(prime, prime + 9001, true);
  prime[0] = prime[1] = false;
  for (int i = 2; i * i <= 9000; i++)
  {
    if (prime[i])
    {
      for (int j = i * i; j <= 9000; j += i)
        prime[j] = false;
    }
  }
}
int main()
{
  init();
  sieve();
  cin >> N >> M;
  for (int i = 0; i < N; i++)
    cin >> arr[i];
  sort(arr, arr + N);
  set<int> s;
  for (int i = 0; i < (1 << N); i++)
  {
    if (__builtin_popcount(i) != M)
      continue;
    int sum = 0;
    for (int j = 0; j < N; j++)
    {
      if (i & (1 << j))
        sum += arr[j];
    }
    if (prime[sum])
      s.insert(sum);
  }
  if (s.empty())
  {
    cout << -1;
    return 0;
  }
  for (auto it : s)
    cout << it << " ";
  return 0;
}
