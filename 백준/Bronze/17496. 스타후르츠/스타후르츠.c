#include <stdio.h>
#include <math.h>
//12865
//int N, K,W[100001],V[100001];
int N, T, C, P;
int main() {
	/*
	scanf("%d %d", &N, &K);
	for (int i=0;i<N;i++){
		scanf("%d %d",&W[i],&V[i]);
	}
	*/
	scanf("%d %d %d %d", &N, &T, &C, &P);
	printf("%d", (N-1) / T * C * P);
}