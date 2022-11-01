#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#define MAX 2147483647
int min(int a, int b) { return a < b ? a : b; }
int main() {
	int N,A,stack[2]={0},num=0,B,C;
	int sum=0;
	scanf("%d",&N);
	for (int i=0;i<N;i++){
		scanf("%d",&A);
		if (A){
			int z=min(A,stack[1]);
			A-=z,stack[1]-=z,num=z,sum+=2*z;
			stack[1]=0;
			z=min(A,stack[0]);
			A-=z,stack[0]-=z,sum+=2*z;
			stack[0]=num;
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
