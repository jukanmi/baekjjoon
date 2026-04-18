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
int ans[4], N;
int cal(int a)
{
  if (a < 65)
    return 0;
  if (a < 95)
    return 1;
  if (a < 125)
    return 2;
  return 3;
}
int main()
{
  init();
  cin >> N;
  int toS = 0, toT = 0;
  int score = 1, time = 4;
  for (int i = 0; i < N; i++)
  {
    if (toT > 240)
    {
      if (toS >= 35)
        ans[cal(toS)]++;
      toS = toT = 0;
      time = 4, score = 1;
    }
    int tmp;
    cin >> tmp;

    if (tmp == 1)
    {
      if (toS >= 35)
        ans[cal(toS)]++;
      toS = toT = 0;
      time = 4, score = 1;
      continue;
    }
    if (tmp == 2)
    {
      if (score >= 2)
        score /= 2;
      else
        time += 2;
    }
    else if (tmp == 3)
    {
    }
    else if (tmp == 4)
    {
      toT += 56;
    }
    else if (tmp == 5)
    {
      time = max(1, time - 1);
    }
    else if (tmp == 6)
    {
      if (score < 32)
        score *= 2;
    }
    toT += time;
    toS += score;
    // cout << toS << " " << toT << endl;
  }

  for (int i = 0; i < 4; i++)
    cout << ans[i] << endl;
  return 0;
}
