#include <stdio.h>
int N,check,j;
char A[51][51],B;
int main() {
	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		scanf("%s", A[i]);
	}
	for (int i = 0; A[0][i]!=NULL; i++) {
		check = 0;
		for (j = 0; j<N-1; j++) {
			if (A[j][i] != A[j + 1][i]) {
				printf("?");
				check = 1;
				break;
			}
		}
		if (check == 0) {
			printf("%c", A[j][i]);
		}
	}
}