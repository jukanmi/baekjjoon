#include <stdio.h>

int main() {
	int m=0,s=0,tmp;
	for (int i=0;i<4;i++){
		scanf("%d",&tmp);
		m+=tmp;
	}
	for (int i=0;i<4;i++){
		scanf("%d",&tmp);
		s+=tmp;
	}
	if (m>=s)printf("%d",m);
	else printf("%d",s);
	return 0;
}
