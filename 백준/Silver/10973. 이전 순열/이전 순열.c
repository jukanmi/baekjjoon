#include <stdio.h>
#include <string.h>
#include <stdbool.h>
int N, arr[10000], i;
bool idx[10001];
int main() {
    scanf("%d", &N);
    for (i = 0; i < N; i++)
        scanf("%d", &arr[i]);
    for (i = N - 1; i > 0; i--) {
        idx[arr[i]] = true;
        if (arr[i] < arr[i - 1])
            break;
    }
    if (!i--)
        puts("-1");
    else {
        for (int j = 0; j < i; j++)printf("%d ", arr[j]);
        idx[arr[i]] = true;
        while (!idx[--arr[i]]);
        printf("%d ", arr[i]);
        idx[arr[i]] = false;
        for (i = N; i > 0; i--)
            if (idx[i])
                printf("%d ", i);
    }
}