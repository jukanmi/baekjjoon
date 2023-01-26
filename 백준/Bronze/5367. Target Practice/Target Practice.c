#include <stdio.h>
int N;
void print_line(){printf("|");for (int i=0; i<N-2; i++)printf("-");puts("|");}
void print(int i){
    printf("|");for (int j=0;j<i;j++)printf(" "); printf("*");
    for (int j=0;j<N-2*(i+2);j++)printf(" ");printf("*");for (int j=0;j<i;j++)printf(" "); puts("|");
}
int main(){
    scanf("%d",&N);
    print_line();
    for (int i=0;i<(N-2)/2;i++)
        print(i);
    printf("|");for (int i=0;i<(N-2)/2;i++)printf(" ");printf("*");for (int i=0;i<(N-2)/2;i++)printf(" ");puts("|");
    for (int i=(N-2)/2-1;i>=0;i--)
        print(i);
    print_line();
}