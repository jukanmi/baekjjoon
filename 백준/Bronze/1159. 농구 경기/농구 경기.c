#include <stdio.h>
int main() {
	int N, s[28]={0};
    char z,a;
    scanf("%d\n",&N);
    while (N--){
        scanf("%c",&z);
        s[z-97]++;
        a=0;
        while (a!=10) scanf("%c",&a);
    }
    for (int i=0;i<28;i++){
        if (s[i]>=5){
            printf("%c",i+97);
            N=1;
        }
    }
    if (N-1){
        printf("PREDAJA");
    }
}