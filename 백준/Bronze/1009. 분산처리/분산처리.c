#include <stdio.h>
int N; a, b,A[11],st;

int main() {
	scanf("%d", &N);
	while (N--) {
		scanf("%d %d", &a, &b);
		int z = 1;
		while (b--) {
			z *= a;
			z =z%10==0?10:z%10;
		}
		printf("%d\n", z);
	
    }
}   