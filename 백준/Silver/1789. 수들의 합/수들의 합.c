#include <stdio.h>

int main() {

	long long i, S, n = 0;
	scanf("%d", &S);

	for (i = 1; n <= S; i++) {
		n += i;
	}

	printf("%d", i - 2);
}