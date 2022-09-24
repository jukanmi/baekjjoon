#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int stair[10]={1,1,1,1,1,1,1,1,1,1};
int main(){
	int n;
    scanf("%d",&n);
    for (int i=0; i<n-1; i++){
        int sum=0;
        for (int j=0; j<10; j++){
            sum+=stair[j];
            stair[j]=sum%10007;
        }
    }
    int sum=0;
    for (int i=0; i<10; i++)sum+=stair[i];
    printf("%d\n",sum%10007);
}