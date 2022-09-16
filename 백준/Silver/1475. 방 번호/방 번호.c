#include <stdio.h>
int N,num[9],ans;
int main() {
	scanf("%d", &N);
	while (N) {
		if (N % 10 == 9) N -= 3;
		if (num[N % 10]) num[N % 10]--;
		else {
			for (int i = 0; i < 9; i++) num[i]++;
			num[6]++;
			num[N % 10]--;
			ans++;
		}
		N /= 10;
	}
	printf("%d", ans);
	return 0;
}
