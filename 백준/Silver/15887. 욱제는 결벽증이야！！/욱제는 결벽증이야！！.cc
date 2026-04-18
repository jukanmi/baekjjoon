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
int N;
int arr[1001];
void rev(int s, int e)
{
  int siz = e - s + 1;
  for (int i = 0; i < siz / 2; i++)
  {
    swap(arr[s + i], arr[e - i]);
  }
}
int main()
{
  init();
  cin >> N;
  for (int i = 0; i < N; i++)
    cin >> arr[i];
  vector<pair<int, int>> ans;
  for (int i = 0; i < N; i++)
  {
    int target = -1;
    bitset<1001> vis;
    vis.set(0);
    for (int j = i; j < N; j++)
    {
      if (arr[j] == i + 1)
        target = j;
      else if (target == -1)
      {
        if (vis[arr[j]] || arr[j] > N)
        {
          target = j;
        }
      }
      vis[arr[j]] = 1;
    }
    if (target != i)
    {
      rev(i, target);
      ans.push_back({i, target});
    }
  }
  cout << ans.size() << endl;
  for (auto &p : ans)
  {
    cout << p.first + 1 << " " << p.second + 1 << endl;
  }
  return 0;
}
