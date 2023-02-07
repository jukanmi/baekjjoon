#include <stdio.h>
#include <stdbool.h>
int N,Q,set;
bool arr[1<<20+1];
int can(int cur){
    if (cur==1&&!arr[1])return set;
    if (arr[cur])set=cur;
    can(cur/2);
}
int main(){
    scanf("%d%d",&N,&Q);
    for (int i=0;i<Q;i++){
        int want;
        scanf("%d",&want);
        set=0;
        int go=can(want);
        arr[want]=true;
        printf("%d\n",go);
    }
}
