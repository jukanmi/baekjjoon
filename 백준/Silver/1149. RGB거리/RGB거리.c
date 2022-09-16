#include <stdio.h>
#include <stdlib.h>
int N, A[1001][3];
//1149
int mini(int a, int b) {
	return a > b ? b : a;
}
int main() {
	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < 3; j++)
			scanf("%d", &A[i][j]);
	}

	for (int i = 1; i <= N; i++) {
		for (int j = 0; j < 3; j++) {
			switch (j)
			{
			case 0:A[i][0] += mini(A[i - 1][1], A[i - 1][2]); break;
			case 1:A[i][1] += mini(A[i - 1][0], A[i - 1][2]); break;
			case 2:A[i][2] += mini(A[i - 1][1], A[i - 1][0]); break;
			default:
				break;
			}
		}
	}
	/*
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < 3; j++) {
			printf("%d ", A[i][j]);
		}
		printf("\n");
	}
	*/
	printf("%d", mini(mini(A[N][0], A[N][1]), A[N][2]));
	return 0;
}