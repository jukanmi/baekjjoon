#include <iostream>
#include <algorithm>
using namespace std;
#define FIO ios_base::sync_with_stdio(0);cin.tie(0); cout.tie(0);
short c[2];
bool dfs(string S, string T, short A, short B) {
	if (S.length() == T.length() && S == T) return true;
	else if (S.length() > T.length()||A<c[0]||B<c[1])return false;
	bool flag = false;
	if (T[T.length() - 1] == 'A' && !flag) {
		T.pop_back();
		flag = dfs(S, T, A - 1, B);
		T.push_back('A');
	}
	if (T[0] == 'B' && !flag) {
		reverse(T.begin(), T.end());
		T.pop_back();
		flag = dfs(S, T, A, B-1);
		T.push_back('B');
		reverse(T.begin(), T.end());
	}
	return flag;
}
int main() {
	FIO;
	short cc[2] = { 0 };
	string S, T;
	cin >> S >> T;
	for (char C : S)
		c[C - 'A']++;
	for (char C : T)
		cc[C - 'A']++;
	puts(dfs(S, T, cc[0], cc[1]) ? "1" : "0");
}