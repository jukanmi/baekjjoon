#include <stdio.h>
typedef unsigned long long ull;
ull fastpow(ull num, ull power, ull MOD) {
	num %= MOD;
	ull ans = 1;
	while (power) {
		if (power % 2 == 1) {
			ans *= num;
			ans %= MOD;
		}
		num = num * num % MOD;
		power /= 2;
	}
	return ans;
}
ull miller(ull n, ull a);
int primecheck(ull num);
int main() {
	int N, ans = 0;
	ull a;
	scanf("%d", &N);
	while (N--) {
		scanf("%llu", &a);
		if (primecheck(2 * a + 1))
			ans++;
	}
	printf("%d\n", ans);
}
int primecheck(ull num) {
	int checklist[3] = { 2,7,61 };
	for (int i = 0; i < 3; i++)
		if (!miller(num, checklist[i])) {
			return 0;
		}
	return 1;
}
ull miller(ull n, ull a) {
	if (a % n == 0) return 1;
	ull k = n - 1;
	while (1) {
		ull tmp = fastpow(a, k, n);
		if (tmp == n - 1) return 1;
		if (k % 2 == 1)
			return (tmp == 1 || tmp == -1);
		k /= 2;
	}

}