#include <stdio.h>
int main() {
    double a[4];
    scanf("%lf%lf%lf%lf", &a[0], &a[1], &a[2], &a[3]);
    double ans = a[0]/a[2]+a[1]/a[3];
    int turn = 0,t=0;
    for (int i = 0; i < 3; i++) {
        t++;
        double s = a[2];
        a[2] = a[3], a[3] = a[1], a[1] = a[0] ,a[0]=s;
        if (a[0] / a[2] + a[1] / a[3] > ans) {
            ans = a[0] / a[2] + a[1] / a[3];
            turn = t;
        }
    }
    printf("%d",turn);
}