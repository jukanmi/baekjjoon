#include <stdio.h>

int main() {
	int n,fi[46];
	fi[0]=0;fi[1]=1;
	scanf("%d", &n);
	for (int i=2;i<=n;i++){
		fi[i]=fi[i-1]+fi[i-2];
	}
	printf("%d",fi[n]);
	return 0;
}
