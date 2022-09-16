#include <stdio.h>
int a[1001],num=0,N,to;
int main() {
	for (int i = 2; i < 1001; i++) {
		if (a[i] == 0) {
			for (int j = 2*i; j < 1001; j += i) {
				a[j] = 1;
			}

		}
	}

	scanf("%d", &N);
	while (N--) {
		scanf("%d", &to);
		if (a[to] == 0 &&to!=1)
			num++;
	}
	printf("%d", num);
}