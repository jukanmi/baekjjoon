#include <stdio.h>
int a[1000001], num = 0, N,M;
int main() {
	a[1] = 1;
	for (int i = 2; i <= 1000001; i++) {
		if (a[i] == 0) {
			for (int j = 2 * i; j <= 1000001; j += i) {
				a[j] = 1;
			}
		}
	}

	scanf("%d %d", &N, &M);
	for (int i = N; i <= M; i++)
		if (a[i] == 0)
			printf("%d\n", i);
}