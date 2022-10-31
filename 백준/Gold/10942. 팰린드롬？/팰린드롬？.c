#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
	int N, arr[2000], M, S, E, pel[2000][2000] = { 0 }, ans[1000000];
	scanf("%d", &N);
	for (int i = 0; i < N; i++)
		scanf("%d", &arr[i]);
	for (int i = 0; i < N; i++) {
		int len = 0;
		while (1) {//짝수 대칭들 모음
			if (arr[i - len] != arr[i + 1 + len]) break;
			pel[i - len][i + 1 + len] = 1;
			if (i - len==0||i+1+len==N-1) break;
			len++;
		}
		len = 0;
		while (1) {//홀수 대칭들 모음
			if (arr[i - len] != arr[i + len])break;
			pel[i - len][i + len] = 1;
			if (i - len == 0 || i + len == N - 1) break;
			len++;
		}
	}
	scanf("%d", &M);
	for (int i=0;i<M;i++) {
		scanf("%d %d", &S, &E);
		ans[i] = pel[S - 1][E - 1];
	}
	for (int i = 0; i < M; i++) {
		printf("%d\n", ans[i]);
	}
}
