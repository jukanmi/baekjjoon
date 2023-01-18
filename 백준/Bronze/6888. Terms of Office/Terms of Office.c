#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
int N,M;
int main(){
    scanf("%d%d",&N,&M);
    for (int i=N;i<=M;i+=60)
    printf("All positions change in year %d\n",i);
}