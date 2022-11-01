#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#define MAX 2147483647
#define ll long long
ll min(ll a, ll b) { return a < b ? a : b; }
int main() {
	ll N,A,num,B,C,sum=0,stack[2]={0};
	scanf("%lld %lld %lld",&N,&B,&C);
	for (ll i=0;i<N;i++){
		scanf("%lld",&A);
		if (B<=C){
			sum+=B*A;
			continue;
		}
		if (A){
			ll z=min(A,stack[1]);
			A-=z,stack[1]-=z,num=z,sum+=C*z;
			stack[1]=0;
			z=min(A,stack[0]);
			A-=z,stack[0]-=z,sum+=C*z;
			stack[0]=num;
			stack[1]+=A;
			sum+=B*A;
		}
		else{
			stack[0]=0,stack[1]=0;
		}
		//printf("stack= %d %d sum=%d\n",stack[0],stack[1],sum);
	}
	printf("%lld",sum);
}
