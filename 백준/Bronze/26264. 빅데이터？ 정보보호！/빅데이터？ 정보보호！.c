#include<stdio.h>
int main(){
    char a;
    while (1){
        scanf("%c",&a);
        if (a==10) break;
    }
    int b[2]={0};
    while (1){
        scanf("%c",&a);
        if (a==10) break;
        if (a=='b') b[0]++;
        if (a=='s') b[1]++;
    }
    if (b[0]<b[1]) printf("security!\n");
    else if (b[0]>b[1]) printf("bigdata?\n");
    else printf("bigdata? security!\n");
    return 0;
}