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
#endif
};
int cnt[2];
int main()
{
  init();
  int N, M;
  cin >> N >> M;
  vector<vector<int>> arr(N, vector<int>(M));

  for (int i = 0; i < N; i++)
  {
    for (int j = 0; j < M; j++)
    {
      int x;
      cin >> x;
      cnt[x]++;
      arr[i][j] = x;
    }
  }
  bool flag = 1;
  for (int i = 0; i < N; i++)
  {
    for (int j = 0; j < M; j++)
    {
      if (i != N - 1 && arr[i][j] == arr[i + 1][j])
        flag = 0;
      if (j != M - 1 && arr[i][j] == arr[i][j + 1])
        flag = 0;
    }
  }
  if (flag || cnt[0] % 2 || cnt[1] % 2)
    cout << -1 << endl;
  else
    cout << 1 << endl;
  return 0;
}