#include <stdio.h>
char temp,before;
int len=0;
int main(){
    while (1){
        scanf("%c",&temp);
        if (temp=='\n') break;
        if (temp!=before) {
            len++;
            before=temp;
        }
    }
    printf("%d\n",len/2);
}