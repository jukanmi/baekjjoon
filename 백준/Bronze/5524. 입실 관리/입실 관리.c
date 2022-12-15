#include<stdio.h>
#include<ctype.h>
#include<string.h>
int main(){
    int N;
    char s[100][22];
    scanf("%d",&N);
    for (int i=0; i<N; i++)
        scanf("%s",s[i]);
    for (int i=0; i<N; i++){
        int len=strlen(s[i]);
        for (int j=0; j<len; j++)
            printf("%c",tolower(s[i][j]));
        printf("\n");
    }
}