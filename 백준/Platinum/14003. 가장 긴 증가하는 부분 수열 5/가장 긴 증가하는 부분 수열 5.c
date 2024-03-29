#include <stdio.h>
int N, A[1000000], temp, len, locate[1000000], S[1000000], ans[1000000];
int main() {
    scanf("%d", &N);
    scanf("%d", &A[len++]);
    S[0] = A[0];
    locate[0] = 0;
    for (int i = 1; i < N; i++) {
        scanf("%d", &temp);
        S[i] = temp;
        if (A[len - 1] < temp) {
            A[len++] = temp;
            locate[i] = len - 1;
        }
        else {
            int l = 0, r = len - 1;
            while (l < r) {
                int m = (l + r) / 2;
                if (A[m] < temp) l = m + 1;
                else r = m;
            }
            A[l] = temp;
            locate[i] = l;
        }
    }
    printf("%d\n", len);
    int z = len;
    len--;
    for (int i = N - 1; i >= 0 && len >= 0; i--)
        if (locate[i] == len)
            ans[len--] = S[i];
    for (int i = 0; i < z; i++)
        printf("%d ", ans[i]);
}