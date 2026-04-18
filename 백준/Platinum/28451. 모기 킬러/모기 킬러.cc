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
int N, L, A, B;
bool checkCanMove(int pos, list<pair<int, int>> &mos)
{
  for (auto &[loc, hel] : mos)
  {
    int relpos = loc - pos;
    if (relpos > A + 2)
      break;
    if (B * min(relpos - 2, A) < hel)
    {
      //cout << "cannot move " << loc << " " << hel << " " << pos << endl;
      return false;
    }
  }
  return true;
}
void spread(int pos, list<pair<int, int>> &mos)
{
  for (auto it = mos.begin(); it != mos.end();)
  {
    auto &[loc, hel] = *it;
    int relpos = loc - pos;
    if (relpos > A)
      break;
    hel -= B;
    if (hel <= 0)
    {
      it = mos.erase(it);
      continue;
    }
    it++;
  }

}
int main()
{
  init();
  cin >> N >> L >> A >> B;
  list<pair<int, int>> mos;
  vector<pair<int, int>> mos2(N);
  vector<int> loc(N), hel(N);
  for (int i = 0; i < N; i++)
    cin >> loc[i];
  for (int i = 0; i < N; i++)
    cin >> hel[i];
  for (int i = 0; i < N; i++)
    mos2[i] = {loc[i], hel[i]};
  sort(mos2.begin(), mos2.end());
  for (int i = 0; i < N; i++)
    mos.push_back(mos2[i]);
  int pos = 0, time = 0;
  while (pos < L+time)
  {
    if (!checkCanMove(pos, mos))
    {
      spread(pos, mos);
      pos++;
      //cout << "spread " << pos << endl;
    }
    else
      pos+=2;
    if (!mos.empty() && pos>=mos.front().first)
    {
      cout << -1;
      return 0;
    }
    time++;
  }
  if (!mos.empty() && pos>=mos.front().first)
    {
      cout << -1;
      return 0;
    }
  cout << time;
  return 0;
}