#include <stdio.h>
#define MAX 2147483647
int main(){
	int N,S,arr[100001]={0},sum=0,a;
	scanf("%d %d",&N,&S);
	for (int i=1;i<=N;i++){
		scanf("%d",&a);
		sum+=a;
		arr[i]=sum;
	}
	int minlen=MAX;
	for (int i=1;i<=N;i++){//앞수
		int left=0,right=i-1;
		while (left<=right){
			int mid=(left+right)/2;
			if (arr[i]-arr[mid]>=S) left=mid+1;
			else right=mid-1;
		}
		if (arr[i]-arr[left-1]>=S&&minlen>i-left+1) minlen=i-left+1;
	}
	if (minlen!=MAX)
		printf("%d",minlen);
	else printf("0");
}