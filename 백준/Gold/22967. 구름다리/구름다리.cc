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
bool connected[301][301];

void Answer(int N)
{
  vector<pair<int, int>> ans;
  if (N <= 4)
  {
    for (int i = 0; i < N; i++)
      for (int j = i + 1; j < N; j++)
        if (!connected[i][j])
          ans.push_back({i + 1, j + 1});
    cout << ans.size() << "\n1\n";
  }
  else
  {
    for (int i = 1; i < N; i++)
      if (!connected[i][0])
        ans.push_back({1, i + 1});
    cout << ans.size() << "\n2\n";
  }
  for (auto &a : ans)
    cout << a.first << " " << a.second << endl;
}

int main()
{
  init();
  int N;
  cin >> N;
  vector<vector<int>> graph(N, vector<int>(0));
  for (int i = 0; i < N - 1; i++)
  {
    int a, b;
    cin >> a >> b;
    a--, b--;
    connected[a][b] = connected[b][a] = 1;
  }
  Answer(N);
  return 0;
}
