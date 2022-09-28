#include <stdio.h>
#include <stdlib.h>
#define MAX 2000*2000
//17404
int min2(int a,int b){return a>b?b:a;}
int min3(int a,int b,int c){return min2(a,b)>c?c:min2(a,b);}
int main() {
	int N, A[1001][3],paint[1001][3],ans=MAX;
	scanf("%d", &N);
	for (int i = 0; i < N; i++)
		for (int j = 0; j < 3; j++)
			scanf("%d", &A[i][j]);
	for (int start=0;start<3; start++){
		for (int i=0;i<3;i++){
			if (i==start)
				paint[0][i]=A[0][i];
			else
				paint[0][i]=MAX;
		}
		for (int i = 1; i < N; i++) {
			paint[i][0]=min2(paint[i-1][1],paint[i-1][2])+A[i][0];
			paint[i][1]=min2(paint[i-1][0],paint[i-1][2])+A[i][1];
			paint[i][2]=min2(paint[i-1][1],paint[i-1][0])+A[i][2];
		}
		for (int i=0;i<3;i++){
			if (i==start) continue;
			ans=min2(ans,paint[N-1][i]);
		}
	}
	printf("%d\n",ans);
	return 0;
}