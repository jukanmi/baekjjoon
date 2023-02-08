#include <stdio.h>

int main() {
	int N,arr[100000],dp[100000]={1};//스텍
	scanf("%d",&N);
	for (int i=0;i<N;i++)
		scanf("%d",&arr[i]);
	int max=0;
	for (int i=1;i<N;i++){
		if (dp[i-1]+1<=arr[i]) dp[i]=dp[i-1]+1;
		else dp[i]=arr[i];
		max=max<dp[i]?dp[i]:max;
	}
	printf("%d\n",max);
}
