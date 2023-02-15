#include <iostream>
#include <algorithm>
using namespace std;
#define FIO ios_base::sync_with_stdio(0);cin.tie(0); cout.tie(0);
string S, T;
int main() {
	FIO;
	cin >> S >> T;
	while (S.length() < T.length()) {
		if (T[T.length() - 1] == 'A')
			T.pop_back();
		else {
			T.pop_back();
			reverse(T.begin(), T.end());
		}
	}
	puts(S == T ? "1" : "0");
}