#include <stdio.h>
char s[55];
int main() {
	int i=0,N;
	scanf("%d\n",&N);
	while (i++<N){
		fgets(s,55,stdin);
		printf("%d. %s",i,s);
	}

	return 0;
}