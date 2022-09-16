#include <stdio.h>
int min(int a,int b){return a<b?a:b;}
int min4(int a,int b,int c,int d){return min(min(a,b),min(c,d));}
int main(){
    int x,y,w,h;
    scanf("%d %d %d %d",&x,&y,&w,&h);
    printf("%d",min4(x,y,w-x,h-y));
}