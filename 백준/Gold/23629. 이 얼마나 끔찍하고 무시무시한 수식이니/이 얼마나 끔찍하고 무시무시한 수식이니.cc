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
pair<string, int> K[] = {
    {"ZERO", 0},
    {"ONE", 1},
    {"TWO", 2},
    {"THREE", 3},
    {"FOUR", 4},
    {"FIVE", 5},
    {"SIX", 6},
    {"SEVEN", 7},
    {"EIGHT", 8},
    {"NINE", 9}};

bool match(string &a, string &b)
{
  if (a.size() < b.size())
    return 0;
  for (int i = 0; i < b.size(); i++)
  {
    if (a[a.size() - b.size() + i] != b[i])
      return 0;
  }
  for (int i = 0; i < b.size(); i++)
    a.pop_back();
  return 1;
}
ll convStr(string s)
{
  if (s == "")
    return -1;
  // cout << "s:" << s << endl;
  ll ret = 0;
  int po = 0;
  while (s != "")
  {
    bool flag = 1;
    for (auto &k : K)
    {
      if (match(s, k.first))
      {
        ret += (ll)pow(10, po) * k.second;
        flag = 0;
        break;
      }
    }
    if (flag)
      return -1;
    po++;
  }
  return ret;
}
void convLL(ll a)
{
  if (a < 0)
  {
    cout << "-";
    a *= -1;
  }
  if (a == 0)
  {
    cout << "ZERO";
    return;
  }
  stack<string> s;
  while (a)
  {
    s.push(K[a % 10].first);
    a /= 10;
  }
  while (!s.empty())
  {
    cout << s.top();
    s.pop();
  }
}
int main()
{
  init();
  string s;
  cin >> s;
  s.pop_back();
  vector<int> cal;
  for (int i = 0; i < s.size(); i++)
    if (s[i] == '+' || s[i] == '-' || s[i] == 'x' || s[i] == '/')
      cal.push_back(i);
  vector<ll> number;
  int indx = 0;
  for (int i = 0; i < cal.size(); i++)
  {
    auto conv = convStr(s.substr(indx, cal[i] - indx));
    if (conv == -1)
    {
      cout << "Madness!";
      return 0;
    }
    number.push_back(conv);
    indx = cal[i] + 1;
  }
  auto conv = convStr(s.substr(indx, s.size()));
  if (conv == -1)
  {
    cout << "Madness!";
    return 0;
  }
  number.push_back(conv);
  if (cal.size() + 1 != number.size())
  {
    cout << "Madness!";
    return 0;
  }
  ll ans = number[0];
  cout << ans;
  for (int i = 0; i < cal.size(); i++)
  {
    cout << s[cal[i]] << number[i + 1];
    switch (s[cal[i]])
    {
    case '+':
      ans += number[i + 1];
      break;
    case '-':
      ans -= number[i + 1];
      break;
    case 'x':
      ans *= number[i + 1];
      break;
    case '/':
      ans /= number[i + 1];
      break;
    default:
      break;
    }
  }
  cout << "=\n";
  convLL(ans);
  return 0;
}
