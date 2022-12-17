#include<stdio.h>
int main(){
    char a;
    while (1){
        scanf("%c",&a);
        if (a==10) break;
    }
    int b=0;
    while (1){
        scanf("%c",&a);
        if (a==10) break;
        if (a=='b') b++;
        if (a=='s') b--;
    }
    if (b<0) printf("security!\n");
    else if (0<b) printf("bigdata?\n");
    else printf("bigdata? security!\n");
    return 0;
}