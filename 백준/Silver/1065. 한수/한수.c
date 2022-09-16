#include <stdio.h>
int n, a=0,C=0;
int s[4] = { 0, };
int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		if (i == 1000) break;
		int s[4] = { 0, };
		a = 0;
		for (int j = i; j > 0; j /= 10) {
			s[a] = j%10;
			a++;
		}
		if (s[0] + s[2] == (2 * s[1]) && s[3] == 0) C++;
		else if (s[2]==0) C++;
	}
	printf("%d", C);
}