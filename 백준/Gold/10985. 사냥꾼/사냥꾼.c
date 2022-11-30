#include <stdio.h>
#include <math.h>
#include <stdlib.h>
double distanceround(double X, double Y, double R) {
    return sqrt(X * X + Y * Y - R * R);
}

int main() {
    int t;
    //freopen("input.txt", "r",stdin);
    double X1, Y1, X2, Y2, R;
    scanf("%d", &t);
    while (t--) {
        scanf("%lf %lf %lf %lf %lf", &X1, &Y1, &X2, &Y2, &R);
        R = fabs(R);
        double dx = X2 - X1, dy = Y2 - Y1;
        if (dx == 0 && dy == 0) {//같은 위치
            printf("0.000\n");
            continue;
        }
        if (dx == 0 && R <= X1 && X1 <= -R) {
            printf("%.3lf\n", sqrt(dx * dx + dy * dy));
            continue;
        }
        
        double x1 = -(dx * sqrt(-dx * dx * Y1 * Y1 + 2 * dx * dy * X1 * Y1 - dy * dy * X1 * X1 + R * R * dy * dy + R * R * dx * dx) + dx * dy * Y1 - dy * dy * X1) / (dy * dy + dx * dx);
        double x2 = (dx * sqrt(-dx * dx * Y1 * Y1 + 2 * dx * dy * X1 * Y1 - dy * dy * X1 * X1 + R * R * dy * dy + R * R * dx * dx) - dx * dy * Y1 + dy * dy * X1) / (dy * dy + dx * dx);
        double zerofar = abs(dx * Y1 - dy * X1) / sqrt(dy * dy + dx * dx);
        if (dx!=0 && (zerofar - R >= 0 ||  (x1<=X1&&x1<=X2) || (X1<=x2&&X2<=x2))) {//안 겹침 zerofar - R <= dbc 두점을 이은 직선이 원안을 지나는가?
            printf("%.3lf\n", sqrt(dx * dx + dy * dy));
            continue;
        }
        double scara1 = sqrt(X1 * X1 + Y1 * Y1), scara2 = sqrt(X2 * X2 + Y2 * Y2);
        double L1 = distanceround(X1, Y1, R), L2 = distanceround(X2, Y2, R);
        double cosse = (X1 * X2 + Y1 * Y2) / (scara1 * scara2);
        double seta = acos(cosse);//두 점사이 백터의 내적
        seta -= (acos(R / scara1) + acos(R / scara2));
        printf("%.3lf\n",L1+L2+seta*R);
    }
}