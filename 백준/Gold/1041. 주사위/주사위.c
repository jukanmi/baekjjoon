#include <stdio.h>
typedef long long ll;
int min(int a, int b) { return a < b ? a : b; }
int max(int a, int b) { return a > b ? a : b; }
int main(void){
    int N,A,B,C,D,E,F;
    scanf("%d",&N);
    scanf("%d %d %d %d %d %d",&A,&B,&C,&D,&E,&F);
    int MIN2 = min(min(min(A+B, A+C), min(A+D, A+E)), min(min(min(B+C, B+D), min(B+F, C+E)), min(min(C+F, D+E), min(D+F, E+F))));
    int MIN3 = min(min(min(A+B+C, A+B+D), min(A+C+E, A+D+E)), min(min(B+C+F, B+D+F), min(C+E+F, D+E+F)));
    int MIN1 = min(min(min(A, B), min(C, D)), min(E, F));
    int MAX1 = max(max(max(A, B), max(C, D)), max(E, F));
    if (N==1)
        printf("%d\n",A+B+C+D+E+F-MAX1);
    else if (N==2)
        printf("%d\n",MIN3*4+MIN2*4);
    else{
        ll ans=0;
        ans+=MIN3*4;
        ans+=MIN2*(8LL*(N-2)+4);
        ans+=MIN1*(4LL*(N-2)*(N-1)+1LL*(N-2)*(N-2));
        printf("%lld\n",ans);
    }
    return 0;
}