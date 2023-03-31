#include <stdio.h>
#include <stdbool.h>
#define len 7368788

bool arr[len];
int main() {
    int cnt = 1, K;
    scanf("%d", &K);
    for (int i = 2; i < len; i++) {
        if (!arr[i]) {
            if (cnt++ == K) {
                printf("%d\n", i);
                return 0;
            }
            for (int j = i * 2; j < len; j += i)arr[j] = 1;
        }
    }
}