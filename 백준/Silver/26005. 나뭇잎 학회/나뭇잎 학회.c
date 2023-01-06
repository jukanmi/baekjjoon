#include <stdio.h>

int main(){
    int N;
    scanf("%d",&N);
    if (N==1)puts("0");
    else{
        if (N%2)printf("%d",N/2*(N+1)+1);
        else printf("%d",N*N/2);
    }
}