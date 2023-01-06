#include <stdio.h>

int main(){
    int T,a,b,c;
    scanf("%d",&T);
    for (int i=1;i<=T;i++){
        scanf("%d%d%d",&a,&b,&c);
        int z=0,ans=0;
        for (int j=0;j<a;j++){
            z+=b;
            ans+=z/c+!!(z%c);
            z%=c;
        }
        printf("Case #%d: %d\n",i,ans);
    }
}