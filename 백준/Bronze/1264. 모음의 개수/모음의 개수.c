#include <stdio.h>
int main(){
    char buf;
    int ans=0;
    while (1){
        scanf("%c",&buf);
        if (buf=='#') break;
        if (buf==10) {
            printf("%d\n", ans);
            ans=0;
        }
        if (buf=='a'||buf=='e'||buf=='i'||buf=='o'||buf=='u'||buf=='A'||buf=='E'||buf=='I'||buf=='O'||buf=='U')
            ans++;
    }
}