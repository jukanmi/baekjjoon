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

int arr[6];
int ans3(int cnt, int sum, int ans)
{
  if (cnt >= 3)
    return ans;
  int ret = ans;
  for (int i = 1; i < 6; i++)
  {
    if (sum + i <= 10)
    {
      ret = max(ret, ans3(cnt + 1, sum + i, ans + arr[i]));
    }
  }
  return ret;
}
int ans4(int cnt, int sum, int ans)
{
  int ret = ans;
  for (int i = 1; i < 6; i++)
  {
    if (sum + i <= 15)
      ret = max(ret, ans4(cnt + 1, sum + i, ans + arr[i]));
  }
  if (cnt <= 3 && sum>=15)
    return 0;
  return ret;
}
int main()
{
  init();
  for (int i = 1; i <= 5; i++)
    cin >> arr[i];
  int ans = 0;
  cout << max(ans3(0, 0, 0), ans4(0, 0, 0));
  return 0;
}
