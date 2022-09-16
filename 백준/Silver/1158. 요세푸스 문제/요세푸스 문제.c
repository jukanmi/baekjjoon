#include <stdio.h>
int M[5001],N,K,i,num=0,none,k=0;
int main() {
	scanf("%d %d", &N, &K);
	printf("<%d",K);
	M[K] = 1;

	i = K;
	while (num!=N-1) {
		i++;
		if (i > N) {
			i %= N;
		}

		if (M[i] == 0) {
			k++;
		}
		if (k == K) {
			k = 0;
			M[i] = 1;
			num++;
			printf(", %d", i);
		}
	}
	printf(">");
	return 0;
}