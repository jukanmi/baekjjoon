#include <stdio.h>
int A, B, C;
int main()
{
    scanf("%d %d %d", &A, &B, &C);
    if (C <= B) {
        printf("-1");
        return 0;
    }
    int i = A / (C - B);
    printf("%d", ++i);
}