#include <stdio.h>
typedef long long ll;

int main(){
    int N;
    ll ans=0;
    scanf("%d",&N);
    for (int i=1;i<=N;i++)
        ans+=i*(N/i);
    printf("%lld\n",ans);
}
