#include <stdio.h>
int main(){
    int a,k;
    scanf("%d%d",&a,&k);
    if (!k) {
        printf("%d",a);
        return 0;
    }
    if (a%2)printf("%d",a);
    else puts("1");
}