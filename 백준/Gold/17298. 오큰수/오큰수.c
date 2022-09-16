#include <stdio.h>
int n, a[1000000], b[1000000], s[1000000], len;


int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &a[i]);
		while (len && a[i] > a[s[len - 1]]) {
			b[s[--len]] = a[i];
			/*
			printf("a: ");
			for (int i = 0; i < n; i++)
				printf("%d ", a[i]);
			printf("\n");
			printf("s: ");
			for (int i = 0; i < n; i++)
				printf("%d ", s[i]);
			printf("\n");
			printf("b: ");
			for (int i = 0; i < n; i++)
				printf("%d ", b[i]);
			printf("\n\n");
			*/
		}
		s[len++] = i;
	}
	for (int i = 0; i < n; i++)
		printf("%d ", b[i] ? b[i] : -1);
}
//10
//3 2 3 4 10 7 2 3 9 8
//4 3 4 10 -1 9 3 9 -1 -1
