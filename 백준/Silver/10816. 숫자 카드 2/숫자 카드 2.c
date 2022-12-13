#include <stdio.h>
int deck[20000001];
int main() {
	int N, M,temp;
	scanf("%d", &N);
	while (N--) {
		scanf("%d", &temp);
		deck[temp >= 0 ? temp + 10000000 : temp * -1]++;
	}
	scanf("%d", &M);
	while (M--) {
		scanf("%d", &temp);
		printf("%d ", deck[temp >= 0 ? temp + 10000000 : temp * -1]);
	}

}