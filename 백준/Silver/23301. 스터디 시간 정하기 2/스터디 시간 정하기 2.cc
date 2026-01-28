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
int N, T, A[1001], addsum[1001];
int main()
{
  init();

  cin >> N >> T;

  for (int i = 0; i < N; i++)
  {
    int tmp;
    cin >> tmp;
    for (int j = 0; j < tmp; j++)
    {
      int s, e;
      cin >> s >> e;
      for (int k = s + 1; k <= e; k++)
        A[k]++;
    }
  }
  for (int i = 1; i <= 1000; i++)
    addsum[i] = addsum[i - 1] + A[i];
  pair<int, int> ans = {0, 0};
  int target = -1;
  for (int i = 0; i + T <= 1000; i++)
  {
    int val = addsum[i + T] - addsum[i];
    //cout << i << " " << val << endl;
    if (val > target)
    {
      ans = {i, i + T};
      target = val;
    }
  }
  cout << ans.first << " " << ans.second << endl;
  return 0;
}