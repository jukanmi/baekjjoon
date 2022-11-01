#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#define MAX 2147483647
int main() {
	int N,A,sum=0,stack[2]={0},num=0;
	scanf("%d",&N);
	for (int i=0;i<N;i++){
		scanf("%d",&A);
		if (A){
			while (A>0&&stack[1]>0){
				A--,stack[1]--,num++,sum+=2;
			}
			stack[1]=0;
			while(A>0&&stack[0]>0){
				A--,stack[0]--,sum+=2;
			}
			stack[0]=num;
			num=0;
			stack[1]+=A;
			sum+=3*A;
		}
		else{
			stack[0]=0,stack[1]=0;
		}
		//printf("stack= %d %d sum=%d\n",stack[0],stack[1],sum);
	}
	printf("%d",sum);
}
