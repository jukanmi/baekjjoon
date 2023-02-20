#include <stdio.h>
#include <string.h>
char T[1000002], P[1000002];
int kmp[1000002];
void mkmp() {
	int plen = strlen(P);
	int stack=0;
	for (int curr = 1; curr < plen; curr++) {
		while (stack > 0 && P[curr] != P[stack])
			stack = kmp[stack - 1];
		if (P[stack] == P[curr]) {
			stack++;
			kmp[curr] = stack;
		}
	}
}
void find() {
	int tlen = strlen(T), plen = strlen(P), sear = 0;
	int ans[1000002],len=0;
	for (int i = 0; i < tlen; i++) {
		if (T[i] == P[sear])
			sear++;
		else {
			if (sear)sear = kmp[sear-1];
			if (T[i] == P[sear])sear++;
			else if (T[i] == P[0]) sear = 1;
			else sear = 0;
		}
		if (sear >= plen) {
			ans[len++] = i - plen + 2;
			sear = kmp[sear-1];
		}
	}
	printf("%d\n", len);
	for (int i = 0; i < len; i++)
		printf("%d ", ans[i]);
	printf("\n");
}
int main() {
	//freopen("input.txt", "r", stdin);
	scanf("%[^\n]s", T);
	getchar();
	scanf("%[^\n]s", P);
	mkmp();
	find();
}
