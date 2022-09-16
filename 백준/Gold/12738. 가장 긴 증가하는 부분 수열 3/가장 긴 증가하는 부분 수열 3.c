#include <stdio.h>
int N,A[1000000],temp,len;
int main() {
	scanf("%d", &N);
	scanf("%d", &A[len++]);
	for (int i = 0; i < N-1; i++) {
		scanf("%d", &temp);
		if (A[len - 1] < temp)
			A[len++] = temp;
		else {
			int l = 0, r = len - 1;
			while (l < r) {
				int m = (l + r) / 2;
				if (A[m] < temp) l = m + 1;
				else r = m;
			}
			A[l] = temp;
		}
	}
	printf("%d", len);
}