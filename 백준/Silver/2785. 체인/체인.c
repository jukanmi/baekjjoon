#include <stdio.h>
#include <stdlib.h>
int q(const void *w, const void *e){return *(int *)w-*(int *)e;}
int main(){
	int N,chain[500001],cut=0;
	scanf("%d",&N);
	int acc=N;
	for (int i=0;i<N;i++){
		scanf("%d",&chain[i]);
	}
	qsort(chain,N,4,q);
	//한덩이를 잘랐을때 다 써야 이을경우
	//한덩이를 잘랐을때 다 안써도 이을경우 <-그리디
	for (int i=0;i<N;i++){
		if (chain[i]+cut>=acc-1){
			printf("%d",acc-1);
			return 0;
		}
		cut+=chain[i];
		acc--;
	}
}