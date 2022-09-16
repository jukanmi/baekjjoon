#include <stdio.h>

int N,num10,num2,num5,M;
int c2(int num) {
	while (num % 2 == 0) {
		num /= 2;
		num2++;
	}
}
int c5(int num) {
	while (num % 5 == 0) {
		num /= 5;
		num5++;
	}
}
int main() {
	scanf("%d", &N);
	for (int i = 1; i <= N; i++) {
		M = i;
		if (M % 10 == 0) {
			while (M%10==0)
			{
				M /= 10;
				num10++;
			}
		}

		if (M % 2 == 0)
			c2(M);
		else if (M % 5 == 0)
			c5(M);

	}
	while (num2 != 0 && num5 != 0) {
		num10 += 1;
		num2--; num5--;
	}
	printf("%d", num10);
}