#include <stdio.h>
#include <stdlib.h>
int N, M, A[8], len, arr[9], tmp, n,swit;
int q(int* w, int* e) { return *w - *e; }
void func() {
	if (len == M) {
		for (int i = 0; i < M; i++)
			printf("%d ", A[i]);
		printf("\n");
		return 0;
	}
	for (int i = 0; i < n; i++) {
		A[len++] = arr[i];
		func();
		len--;
	}
	return 0;
}
int main() {
	scanf("%d %d", &N, &M);
	for (int i = 0; i < N; i++) {
		scanf("%d", &tmp);
		swit = 1;
		for (int i = 0; i < n; i++) {
			if (arr[i] == tmp)
				swit = 0;
		}
		if (swit) {
			arr[n++] = tmp;
		}
	}
	qsort(arr, n, 4, q);
	func(M);
	return 0;
}
