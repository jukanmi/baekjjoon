#include <stdio.h>
int A[51], B[51], C[51], n, num = 0, D[51],small=101,c;
int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &A[i]);
	}
	for (int i = 0; i < n; i++) {
		scanf("%d", &B[i]);
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (B[i] > B[j]) {
				C[i]++;
			}
		}
		C[i] = n - C[i];
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (small > A[j]) {
				small = A[j];
				c = j;
			}
		}
		A[c] = 101;
		D[i] = small;
		small = 101;
	}

	c = 0;
	for (int i = 0; i < 101; i++) {
		for (int j = 0; j < n; j++) {
			if (i == C[j]) {
				num += B[j] * D[c];
				c++;
			}
		}
	}
	printf("%d", num);
}