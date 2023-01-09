#include <stdio.h>
int min(int a, int b) { return a < b ? a : b; }
int max(int a, int b) { return a > b ? a : b; }
typedef long long ll;
int main(){
    int a,b;
    scanf("%d%d",&a,&b);
    a=100-a,b=100-b;
    int c=100-a-b,d=a*b;
    printf("%d %d %d %d %d %d\n%d %d",a,b,c,d,d/100,d%100,(100-a)*(100-b)/100,(100-a)*(100-b)%100);
}