#include <stdio.h>

int main(){
	int T,N,M;
	scanf("%d",&T);
	for (int c=1;c<=T;c++){
		scanf("%d%d",&N,&M);
		printf("Case #%d:\n",c);
		for (int a=0;a<2;a++){
			printf("..");
			printf(a%2?"|":"+");
			for (int i=0;i<2*(M-1);i++){
				if (a%2)printf(i%2?"|":".");
				else printf(i%2?"+":"-");
			}
			printf("\n");
		}
		for (int i=0;i<2*M+1;i++)
			printf(i%2?"-":"+");
		printf("\n");
		//한줄완
		for (int a=1;a<N;a++){
			for (int i=0;i<M;i++)
				printf("|.");
			puts("|");
			for (int i=0;i<M;i++)
				printf("+-");
			puts("+");
		}
	}

}