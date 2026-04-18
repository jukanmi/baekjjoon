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
  // freopen("out.txt", "w", stdout);
#endif
}
const int MAX = 400+5;
int N,P;
int capacity[MAX][MAX];
int flow[MAX][MAX];
vector<int> adj[MAX];
int parent[MAX];
int totalFlow;
bool visited[MAX];
void addEdge(int u, int v, int cap)
{
  adj[u].push_back(v);
  adj[v].push_back(u);
  capacity[u][v] = cap;
}
bool bfs(int source, int sink)
{
  memset(visited, 0, sizeof(visited));
  queue<int> q;
  q.push(source);
  visited[source] = true;
  while (!q.empty())
  {
    int cur = q.front();
    q.pop();
    if (cur == sink)
      return true;
    for (int& next : adj[cur])
    {
      if (!visited[next] && capacity[cur][next] - flow[cur][next] > 0)
      {
        visited[next] = true;
        parent[next] = cur;
        q.push(next);
      }
    }
  }
  return false;
}
void maxFlow(int source, int sink)
{
  while (bfs(source, sink))
  {
    int cur = sink;
    int minFlow = INF;
    while (cur != source)
    {
      //cout << cur << " ";
      int prev = parent[cur];
      minFlow = min(minFlow, capacity[prev][cur] - flow[prev][cur]);
      cur = prev;
    }
    cur = sink;
    while (cur != source)
    {
      int prev = parent[cur];
      flow[prev][cur] += minFlow;
      flow[cur][prev] -= minFlow;
      cur = prev;
    }
    totalFlow += minFlow;
  }
  //cout << endl;
}
int main()
{
  init();
  cin >> N >> P;
  int source = 1;
  int sink = 2;
  for (int i = 0; i < P; i++){
    int v,c;
    cin >> v >> c;
    addEdge(v,c,1);
  }
  maxFlow(source, sink);
  cout << totalFlow << endl;
  return 0;
}