#include <stdio.h>
int main(){
    int a,k;
    scanf("%d%d",&a,&k);
    printf("%d",a%2||!k?a:1);
}