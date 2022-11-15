#include <stdio.h>
#include <stdlib.h>
int arr[10], tmp, n;
int N, M, visit[10001], A[9], len, swit, num[10001];
int q(int* w, int* e) { return *w - *e; }
void func(int z) {
	if (len == M) {
		for (int i = 0; i < M; i++) {
			printf("%d ", A[i]);
		}
		printf("\n");
		return;
	}

	for (int i = z; i < n; i++) {
		if (visit[arr[i]] < num[arr[i]]) {
			visit[arr[i]]++;
			A[len++] = arr[i];
			func(i);
			len--;
			visit[arr[i]]--;
		}
	}

	return;
}
int main() {
	scanf("%d %d", &N, &M);
	for (int i = 0; i < N; i++) {
		scanf("%d", &tmp);
		num[tmp]++;
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
	func(0);
	return 0;
}

