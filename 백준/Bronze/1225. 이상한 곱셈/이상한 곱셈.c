#include <stdio.h>
#define m 10000
int a[2][m],A,B;
long long f;
char c;
int main(){
    while (1){
        scanf("%c",&c);
        if (c==10) break;
        if (c==32){A=B,B=0,f=1;continue;}
        a[f][B++]=c-48;
    }
    f=0;
    while (A--)
        for (int i=0;i<B;i++)
            f+=a[0][A]*a[1][i];
    printf("%lld\n",f);
}