#include <stdio.h>
// A0 G1 C2 T3
int N;
int arr[1000000];
char c;
int dict[4][4]={{0,2,0,1},{2,1,3,0},{0,3,2,1},{1,0,1,3}};
int main(){
    scanf("%d\n",&N);
    for (int i=0; i<N; i++){
        scanf("%c",&c);
        if (c=='A')arr[i]=0;
        else if (c=='G')arr[i]=1;
        else if (c=='C')arr[i]=2;
        else arr[i]=3;
    }
    while (N-->1)
        arr[N-1]=dict[arr[N-1]][arr[N]];
    if (arr[0]==0)puts("A");
    else if (arr[0]==1)puts("G");
    else if (arr[0]==2)puts("C");
    else puts("T");
}