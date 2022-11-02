#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#define MAX 2147483647
#define ll long long
int main(){
	int T,x,y;
	scanf("%d",&T);
	while (T--){
		scanf("%d %d",&x,&y);
		ll a=0;
		int tmp=y-x;
		while (tmp>a*(a+1))
			a++;
		if (a*(a)-tmp>=0) printf("%d\n",2*a-1);
		else printf("%d\n",2*a);
	}
}
