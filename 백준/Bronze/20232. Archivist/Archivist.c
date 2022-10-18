#include <stdio.h>
int a[25];
void p(int x){
	if (!x--) printf("ITMO");
	else if (!x--) printf("SPbSU");
	else printf("PetrSU, ITMO");
}
int main(){
    a[1]=1,a[2]=1,a[5]=1,a[11]=2,a[12]=1,a[13]=1,a[18]=1,a[23]=1;
	int n;
	scanf("%d",&n);
	p(a[n-1995]);
    return 0;
}