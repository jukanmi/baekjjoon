#include <stdio.h>
int T, N, M;

unsigned long long bri(int a, int b) {
	 unsigned long long cot=1;
	if (b - a < a)
		a = b - a;
	cot = a + 1;
	for (int i = a + 2; i <= b; i++) {
		cot *= i;
		cot /= i - a;
	}
	return cot;// b-(b-a-1)+1
}
int main() {
	scanf("%d", &T);
	while (T--) {
		scanf("%d %d", &N, &M);

		printf("%lld\n", bri(N, M));
	}
}