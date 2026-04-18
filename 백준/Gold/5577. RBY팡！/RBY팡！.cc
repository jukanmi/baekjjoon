#include <bits/stdc++.h>
using namespace std;
using ll = long long;
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
int simulate(int indx, vector<int> &L, int N, bool up)
{
  stack<pair<int, int>> q;
  bool shift = 0;
  int i;
  int pang = 0;
  int panging = 0;
  for (i = 0; i < N; i++)
  {
    if (indx == i)
    {
      pang = 0;
      if (up)
      {
        q.top().second++;
        if (q.top().second >= 4)
          q.pop();
      }
      else if (!up)
        shift = 1;
      continue;
    }
    if (panging == L[i])
      continue;
    if (q.empty())
    {
      q.push({L[i], 1 + shift});
      shift = 0;
      continue;
    }
    int color = q.top().first;
    int& cnt = q.top().second;
    if (color == L[i])
    {
      cnt += 1 + shift;
    }
    else
    {
      q.push({L[i], shift + 1});
    }
    shift = 0;
    panging = 0;
    pang++;
    if (q.top().second >= 4)
    {
      panging = q.top().first;
      q.pop();
      pang = 0;
    }
    if (indx <= i && pang >= 4){
      i++;
      break;
    }
  }
  int ans = N - i;
  while (!q.empty())
  {
    ans += q.top().second;
    q.pop();
  }
  return ans;
}
int main()
{
  init();
  int N;
  cin >> N;
  vector<int> L(N);
  int cnt = 0, cur = 0;
  for (int i = 0; i < N; i++)
  {
    cin >> L[i];
  }
  int minVal = INT_MAX;
  for (int i = 0; i < N; i++)
  {
    if (i != 0)
      minVal = min(minVal, simulate(i, L, N, 1));
    if (i != N - 1)
      minVal = min(minVal, simulate(i, L, N, 0));
  }
  cout << minVal;
  return 0;
}
