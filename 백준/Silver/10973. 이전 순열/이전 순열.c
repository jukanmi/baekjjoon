#include <stdio.h>
#include <string.h>
#include <stdbool.h>
int N, arr[10000], i;
bool idx[10001];
int main() {
    scanf("%d", &N);
    for (i = 0; i < N; i++) {
        scanf("%d", &arr[i]);
    }
    for (i = N - 1; i > 0; i--) {
        idx[arr[i]] = true;
        if (arr[i] < arr[i - 1]){
            int a = i-1;
            idx[arr[a]] = true;
            for (int j = arr[i-1] - 1; j >=0 ; j--) {
                if (idx[j]) {
                    idx[j] = false;
                    arr[a++] = j;
                    break;
                }
            }
            for (int j = N; j >0; j--) {
                if (idx[j]) {
                    arr[a++] = j;
                }
            }
            break;
        }
    }
    if (!i)
        puts("-1");
    else
        for (i = 0; i < N; i++)
            printf("%d ", arr[i]);
}