#include <stdio.h>
int K, N, k[10001], num,no;
long long low = 1, high = 2147483648,mid;
int main() {
	scanf("%d %d", &K, &N);
	for (int i = 0; i < K; i++)
		scanf("%d", &k[i]);
	while (low<high) {
		mid = (low + high) / 2;
		num = 0;
		for (int i = 0; i < K; i++) {
			num += (k[i] / mid);
		}
		if (num >= N) low = mid+1;
		else high = mid;
	}
	printf("%d", low-1);
}