#include <stdio.h>
int N, A, B;
void max(int *a, int *b) {
	if (*a<*b) {
		int temp = *b;
		*b = *a;
		*a = temp;
	}
}
int ucid(int a, int b) {
	if (a % b == 0)
		return b;
	return ucid(b, a % b);
}
int main() {
	scanf("%d", &N);
	while (N--) {
		scanf("%d %d", &A, &B);
		max(&A, &B);
		printf("%d\n", A*B/ucid(A, B));
	}
}