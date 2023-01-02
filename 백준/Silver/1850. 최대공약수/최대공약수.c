#include <stdio.h>
typedef long long ll;
ll gcd(ll a, ll b)
{
  if(b==0) return a;
  return gcd(b,a%b);
}
int main(void) {
	ll a,b;
	scanf("%lld %lld",&a,&b);
	if (a>b){
        ll tmp=a;
        a=b;
        b=tmp;
    }
    ll repeat=gcd(a,b);
    
    while (repeat--)
        printf("1");
}