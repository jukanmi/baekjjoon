#include <stdio.h>
#define MAX 2100000000

int main(){
	int N,K,coin[101],tmp,dp[10001]={MAX};
	dp[0]=0;
	scanf("%d%d",&N,&K);
	int len=0;
	for (int i = 0; i < N; i++)
		scanf("%d",&coin[len++]);
	for (int i = 1; i<=K;i++){
		int a=MAX;
		for (int j=0;j<N;j++)
			if (i-coin[j]>=0)
				a=a>dp[i-coin[j]]+1?dp[i-coin[j]]+1:a;
		dp[i]=a;
	}
	if (dp[K]==MAX) printf("-1");
	else printf("%d",dp[K]);
}
