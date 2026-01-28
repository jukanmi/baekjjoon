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
  // freopen("output.txt", "w", stdout);
#endif
};
int N, T;
int main()
{
  init();
  ll A[100001] = {
      0,
  };
  cin >> N >> T;
  priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
  priority_queue<int, vector<int>, greater<int>> endpq;
  for (int i = 0; i < N; i++)
  {
    int tmp;
    cin >> tmp;
    for (int j = 0; j < tmp; j++)
    {
      int s, e;
      cin >> s >> e;
      pq.push({s, e});
    }
  }
  ll human = 0;
  for (int i = 0; i <= 100000; i++)
  {
    while (!pq.empty() && pq.top().first == i)
    {
      human++;
      endpq.push(pq.top().second);
      pq.pop();
    }
    while (!endpq.empty() && endpq.top() == i)
    {
      human--;
      endpq.pop();
    }
    A[i] = human;
  }

  for (int i = 1; i <= 100000; i++)
  {
    A[i] += A[i - 1];
  }

  pair<int, int> ans = {0, 0};
  ll target = -1;
  for (int i = 0; i + T <= 100000; i++)
  {
    ll val = A[i + T - 1] - (i == 0 ? 0 : A[i - 1]);
    // cout << i << " " << val << endl;
    if (val > target)
    {
      ans = {i, i + T};
      target = val;
    }
  }
  cout << ans.first << " " << ans.second << endl;
  return 0;
}