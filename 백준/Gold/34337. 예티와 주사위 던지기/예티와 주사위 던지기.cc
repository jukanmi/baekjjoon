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
// 조합에 따른 점수 계산
int calcul(vector<int> &dice)
{
  int d[7] = {
      0,
  };
  for (int i = 0; i < 5; i++)
    d[dice[i]]++;
  int score = 0;
  for (int i = 1; i <= 6; i++)
  {
    score = max(score, i * d[i]);
    if (d[i] >= 5)
      score = 50;
  }
  return score;
}
int func(vector<int> &dice, int cnt)
{
  if (cnt == 5)
    return calcul(dice);
  if (dice[cnt])
    return func(dice, cnt + 1);
  int ret = 0;
  for (int i = 1; i <= 6; i++)
  {
    dice[cnt] = i;
    ret += func(dice, cnt + 1);
    dice[cnt] = 0;
  }
  return ret;
}
// bit에 따른 주사위 재굴리기
int case_dice(vector<int> &dice, int bit)
{
  vector<int> temp = dice;
  for (int i = 0; i < 5; i++)
    if (bit & (1 << i))
      temp[i] = 0;
  int cnt = __builtin_popcount(bit);
  return func(temp, 0) * pow(6, 5 - cnt);
}
int main()
{
  init();
  vector<int> dice(5);
  for (int i = 0; i < 5; i++)
    cin >> dice[i];
  int ans = 0;
  for (int i = 0; i < (1 << 5); i++)
    ans = max(ans, case_dice(dice, i));
  cout << ans << endl;
  return 0;
}
