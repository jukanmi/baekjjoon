#include <stdio.h>
int N, F;
int main() {
	scanf("%d", &N);
	scanf("%d", &F);
	N /= 100;
	N *= 100;
	for (int i = 0; i < 100; i++) {
		if ((N + i) % F == 0) {
			if (i < 10)
				printf("0%d", i);
			else
				printf("%d", i);
			return 0;
		}
	}
}