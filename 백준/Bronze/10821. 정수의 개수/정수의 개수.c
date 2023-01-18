#include <stdio.h>
int a;
int main(){
    char c;
    while (1){
        scanf("%c",&c);
        if (c == '\n'||c=='\0')break;
        if (c==',')a++;
    }
    printf("%d\n",a+1);
}