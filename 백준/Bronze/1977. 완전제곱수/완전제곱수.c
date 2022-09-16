#include <stdio.h>
#include <math.h>
int main() {
	int m, n,num=0,min=0;
	scanf("%d", &m);
	scanf("%d", &n);
	for (int i = m; i <= n; i++) {
		for (int j = 1; j <= 100; j++) {
			if (i == pow(j, 2)) {
				num += i;
				if (min == 0) min = i;
			}
		}
	}
	if (min != 0) {
		printf("%d\n", num);
		printf("%d", min);
	}
	else {
		printf("-1");
	}
}