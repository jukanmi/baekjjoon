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

int graph[10][10];
int ans = -1;
bool vis[10];
int viscnt = 0;
int N, M;
void func(int cur, int sum)
{
  if (viscnt < N + 1 && !cur && sum)
    return;
  if (viscnt >= N + 1 && !cur)
  {
    ans = max(ans, sum);
    return;
  }
  for (int i = 0; i <= N; i++)
  {
    if (!graph[cur][i])
      continue;
    auto edge = make_pair(i,graph[cur][i]);
    if (!vis[edge.first])
    {
      vis[edge.first] = 1;
      viscnt++;
      func(edge.first, sum + edge.second);
      viscnt--;
      vis[edge.first] = 0;
    }
  }
}
int main()
{
  init();
  cin >> N >> M;
  for (int i = 0; i < M; i++)
  {
    int u, v, d;
    cin >> u >> v >> d;
    graph[u][v] = max(graph[u][v], d);
  }
  func(0, 0);
  cout << ans;
  return 0;
}
