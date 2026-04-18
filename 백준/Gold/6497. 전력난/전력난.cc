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

int find_parent(vector<int> &parent, int u)
{
  if (parent[u] == u)
  {
    return u;
  }
  return parent[u] = find_parent(parent, parent[u]);
}
// 분리집합
void union_parent(vector<int> &parent, int u, int v)
{
  u = find_parent(parent, u);
  v = find_parent(parent, v);
  if (u < v)
  {
    parent[v] = u;
  }
  else
  {
    parent[u] = v;
  }
}

int kruskal(vector<vector<pair<int, int>>> &bridges, int n)
{
  vector<int> parent(n + 1);
  for (int i = 0; i < n; i++)
  {
    parent[i] = i;
  }
  vector<pair<int, pair<int, int>>> edges;
  for (int i = 0; i < n; i++)
  {
    for (auto& [j, w] : bridges[i])
    {
      edges.push_back({w, {i, j}});
    }
  }
  sort(edges.begin(), edges.end());
  int cost = 0;
  for (auto& [w, edge] : edges)
  {
    auto& [u, v] = edge;
    if (find_parent(parent, u) != find_parent(parent, v))
    {
      cost +=w;
      union_parent(parent, u, v);
    }
  }
  return cost;
}
int main()
{
  init();
  int m, n;
  while (1)
  {
    cin >> m >> n;
    if (!m && !n)
      break;
    vector<vector<pair<int, int>>> bridges(m+1);
    int allCost = 0;
     for (int i = 0; i < n; i++)
    {
      int x, y, z;
      cin >> x >> y >> z;
      bridges[x].push_back({y,z});
      bridges[y].push_back({x,z});
      allCost +=z;
    }
    cout << allCost-kruskal(bridges,m) << endl;
  }
  return 0;
}
