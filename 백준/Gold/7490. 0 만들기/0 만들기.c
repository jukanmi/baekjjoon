#include <stdio.h>
int T, N;
char pm[11];
void teck(int num, int total, int before)
{
    //printf("%d\n", total);
    if (num > N) {
        if (total == 0)
        {
            printf("1");
            for (int i = 2; i <= N; i++)
                printf("%c%d", pm[i], i);
            printf("\n");
        }
        return;
    }
    pm[num] = 32;
    if (before > 0)
        teck(num + 1, total+before*9+num, before * 10 + num);
    else
        teck(num + 1, total+before*9-num, before * 10 - num);
    pm[num] = 43;
    teck(num + 1, total + num, num);
    pm[num] = 45;
    teck(num + 1, total - num, -num);
}
int main()
{
    scanf("%d", &T);
    while (T--)
    {
        scanf("%d", &N);
        teck(2, 1, 1);
        printf("\n");
    }
    return 0;
}
