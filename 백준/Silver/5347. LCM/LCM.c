#include <stdio.h>
long long gcd(long long a, long long b) {
	if (a > b) {
		long long temp = a;
		a = b;
		b = temp;
	}
	while (b%a) {
		b %= a;
		long long temp = b;
		b = a;
		a = temp;
	}
	return a;
}
int main(){
    long long t,a,b;
    scanf("%lld",&t);
    while (t--) {
        scanf("%lld %lld",&a,&b);
        long long ans = a*b;
        printf("%lld\n",ans/gcd(a,b));
    }
    return 0;
}