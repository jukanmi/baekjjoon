#include <stdio.h>
int N,K,arr[100],dp[10001]={1};
int main(){
	scanf("%d%d",&N,&K);
	for (int i=0; i<N; i++)
		scanf("%d",&arr[i]);
	for (int i=0;i<N;i++)
		for (int j=arr[i]; j<=K;j++)
			dp[j]+=dp[j-arr[i]];
	printf("%d\n",dp[K]);
}