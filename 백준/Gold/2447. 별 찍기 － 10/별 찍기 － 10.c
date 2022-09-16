#include <stdio.h>
#include <stdlib.h>
#include <string.h>
char star[2188][2188];
char base[3][3] = {
    {42,42,42},
    {42,32,42},
    {42,42,42}
};
int n;
int print_star(int x, int y, int n) {
    if (n == 3) {
        for (int i = 0; i < 3; i++)
            for (int j = 0; j < 3; j++)
                star[x + i][y + j] = base[i][j];
        return 0;
    }
    n /= 3;
    for (int i = 0; i < 3; i++)
        print_star(x, y + i * n, n);
    print_star(x + n, y, n);
    print_star(x + n, y + 2 * n, n);
    for (int i = 0; i < 3; i++)
        print_star(x + 2 * n, y + i * n, n);
    return 0;
}
int main() {
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
        memset(star[i], 32, sizeof(char) * n);
    print_star(0, 0, n);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++)
            printf("%c", star[i][j]);
        printf("\n");
    }
    return 0;
}