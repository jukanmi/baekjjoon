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
int timeToNum(string s)
{
  return stoi(s.substr(0, 2)) * 60 + stoi(s.substr(3));
}

int main()
{
  init();
  int N, M, P;
  cin >> N >> M >> P;
  int wrongtime[101][101];
  bool finish[101][101];
  memset(wrongtime, -1, sizeof(wrongtime));
  memset(finish, 0, sizeof(finish));
  map<string, int> mm;
  vector<string> nc;
  for (int i = 0; i < M; i++)
  {
    string s;
    cin >> s;
    nc.push_back(s);
  }
  sort(nc.begin(),nc.end());
  for (int i=0;i<M;i++){
    mm[nc[i]] = i;
  }
  vector<vector<int>> score(N+1, vector<int>(M+1, 0));
  for (int i = 0; i < P; i++)
  {
    int prob;
    string t, n, can;

    cin >> prob >> t >> n >> can;
    prob--;
    int time = timeToNum(t), name = mm[n];
    bool flag = (can == "solve");
    if (finish[prob][name])
      continue;
    if (flag)
    {
      finish[prob][name] = 1;
      if (wrongtime[prob][name] != -1)
      score[prob][name] = -(time - wrongtime[prob][name]);
    }
    else
    {
      if (wrongtime[prob][name] == -1)
      {
        wrongtime[prob][name] = time;
      }
    }
  }

  vector<int> ans(M+1, 0);
  vector<pair<int, int>> r[N+1];
  for (int i = 0; i < N; i++)
  {
    for (int j = 0; j < M; j++)
    {
      if (score[i][j])
      {
        r[i].push_back({-score[i][j], j});
      }
      else if (finish[i][j] || wrongtime[i][j] == -1)
      {
        ans[j] += (M + 1);
      }
      else
        ans[j] += M;
    }
  }
  for (int i = 0; i < N; i++)
  {
    sort(r[i].begin(), r[i].end());
    int indx = 1;
    for (auto &rr : r[i])
    {
      ans[rr.second] += indx;
      indx++;
    }
  }
  vector<pair<int, string>> sor;
  for (int j = 0; j < M; j++)
    sor.push_back({ans[j], nc[j]});
  sort(sor.begin(), sor.end());
  for (auto &c : sor)
    cout << c.second << endl;
  return 0;
}
