#include <stdio.h>
int min(int a, int b) { return a < b ? a : b; }
typedef long long ll;
void divide(int a, int b){
    int mininum=min(a,b);
    for (int i=mininum; i>1; i--){
        if (a%i==0&&b%i==0){
            printf("%d/%d\n",a/i,b/i);
            return ;
        }
    }
    printf("%d/%d\n",a,b);
}
int main(){
    int N,a,b;
    scanf("%d",&N);
    scanf("%d",&a);
    N--;
    while (N--){
        scanf("%d",&b);
        divide(a,b);
    }
}