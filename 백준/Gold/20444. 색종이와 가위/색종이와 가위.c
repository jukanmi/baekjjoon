#include <stdio.h>

long long left, right,n, mid, k;
int main() {
    scanf("%lld", &n);
    scanf("%lld", &k);
    
    left = 0;
    right = n % 2 == 0 ? n / 2 : n / 2 + 1;
    for (int i = 0; i < 100; i++) {
         mid = (left + right) % 2 == 0 ? (left + right) / 2 : (left + right) / 2 + 1;
        if ((n - mid + 1) * (mid + 1) <= k) left = mid;
        else right = mid;
    }
    for (long long i = left; i <= right; i++) {
        if ((n - i + 1) * (i + 1) == k) {
            printf("YES");
            return 0;
        }
    }
    printf("NO");
    return 0;
}