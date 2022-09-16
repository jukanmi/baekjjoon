#include <stdio.h>
int x,i=1;
int main() {
	scanf("%d", &x);
	while ((i * (i + 1)) / 2 < x)
		i++;
	i--;
	int m = x - (i * (i + 1)) / 2;
	if (i % 2 == 0)
		printf("%d/%d", i + 2 - m, m);
	else
		printf("%d/%d", m, i + 2 - m);
}