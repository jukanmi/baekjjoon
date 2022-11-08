#include <stdio.h>
#define MAX 4000000
int main() {
	int IR[MAX+1]={0},len=0,prime[283147];
    for (int i=2;i<=MAX;i++){
        if (!IR[i]){
            prime[len++]=i;
            for (int j=2*i;j<=MAX;j+=i)
                IR[j]=1;
        }
    }
    int N;
    scanf("%d",&N);
    int sum=0,ans=0,end=0;
    for (int start=0;start<len;start++){
        while (sum < N && end < len)
            sum+=prime[end++];
        if (sum == N) ans++;
        sum-=prime[start];
    }
    printf("%d",ans);
}
