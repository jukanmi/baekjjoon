#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define endl "\n"

const ll INF = 2147483647;
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

pair<ll, ll> find_incline(int x1, int y1, int x2, int y2)
{
  ll dy = y2 - y1;
  ll dx = x2 - x1;
  ll g = __gcd(abs(dy), abs(dx));
  dy /= g;
  dx /= g;
  if (dx < 0)
  {
    dy = -dy;
    dx = -dx;
  }
  return {dx, dy};
}
pair<ll, ll> find_y(pair<ll, ll> a, ll x, ll y)
{
  ll dy = a.second * x - a.first * y;
  ll dx = a.first;
  ll g = __gcd(abs(dy), abs(dx));
  dy /= g;
  dx /= g;
  if (dx < 0)
  {
    dy = -dy;
    dx = -dx;
  }
  return {dx, dy};
}
int cntLines(set<pair<ll, ll>> &lines)
{
  int count = 0;
  ll lastEnd = -INF;
  for (const auto &line : lines)
  {
    if (line.first > lastEnd)
      count++;
    lastEnd = max(lastEnd, line.second);
  }
  return count;
}
int main()
{
  init();
  int N;
  cin >> N;
  map<array<ll, 4>, set<pair<ll, ll>>> mp; // y = (a2/a1)x + (b2/b1)
  map<ll, set<pair<ll, ll>>> vertical;     // x = k
  map<ll, set<pair<ll, ll>>> horizontal;   // y = k
  for (int i = 0; i < N; i++)
  {
    double a, b, c, d;
    cin >> a >> b >> c >> d;
    ll x1, y1, x2, y2;
    x1 = (ll)(a * 100 + .5);
    y1 = (ll)(b * 100 + .5);
    x2 = (ll)(c * 100 + .5);
    y2 = (ll)(d * 100 + .5);
    if (x1 == x2)
    {
      if (y1 > y2)
        swap(y1, y2);
      vertical[x1].insert({y1, y2});
      continue;
    }
    else if (y1 == y2)
    {
      if (x1 > x2)
        swap(x1, x2);
      horizontal[y1].insert({x1, x2});
      continue;
    }
    if (x1 > x2)
      swap(x1, x2), swap(y1, y2);
    ll a1, a2, b1, b2;
    tie(a1, a2) = find_incline(x1, y1, x2, y2);
    tie(b1, b2) = find_y({a1, a2}, x1, y1);
    mp[{a1, a2, b1, b2}].insert({x1, x2});
  }
  int cnt = 0;
  for (auto &p : mp)
    cnt += cntLines(p.second);
  for (auto &p : vertical)
    cnt += cntLines(p.second);
  for (auto &p : horizontal)
    cnt += cntLines(p.second);
  cout << cnt << endl;
  return 0;
}