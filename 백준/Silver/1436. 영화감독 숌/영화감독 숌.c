#include <stdio.h>
#include <stdlib.h>
#include <math.h>
int n, c=0, m, count=0;
int s[10001];
int cheak(int a) {
	m = 0;
	for (int i = a; i > 0; i /= 10) {
		if (i % 10 == 6)
			m++;
		else
			m = 0;
		if (m == 3) {
			c = 1;
			break;
		}
		else
			c = 0;
	}
}
int main() {
	scanf("%d", &n);
	for (int i = 1; ; i++) {
		m = 0;
		for (int j = i; j > 0; j /= 10) {
			if (j % 10 == 6)
				m++;
			else
				m = 0;
			if (m == 3) {
				c = 1;
				break;
			}
			else
				c = 0;
		}
		if (c == 1) {
			count++;
			s[count] = i;
			if (n == count) {
				printf("%d\n", s[count]);

				return 0;
			}
			
		}
	}
}