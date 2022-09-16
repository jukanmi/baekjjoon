#include <stdio.h>
int N,A[10];
int main() {
	scanf("%d", &N);
	while (N) {
		A[N % 10]++;
		N /= 10;
	}
	for (int i = 9; i >= 0; i--)
		while (A[i]--)
			printf("%d", i);
}