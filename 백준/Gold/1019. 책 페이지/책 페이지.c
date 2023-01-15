#include <stdio.h>
#include <math.h>
int N;
int arr[10];
void cnt(int num) {
    if (num <= 0)return;
    int power = -1;
    while (num >= pow(10, ++power));
    power--;
    int cur[10] = { 0 };
    while (power >= 0) {
        int a = num / pow(10, power);
        if (!a) {
            cur[0]++;
            for (int i = 0; i < power; i++)
                arr[0] -= 9 * pow(10, i);
            power--;
            continue;
        }
        num -= a * pow(10, power);//한자릿수씩 때어풀기
        for (int i = 0; i < 10; i++)
            arr[i] += cur[i] * a * pow(10, power);// 이전 차항
        if (power) {
            for (int i = 0; i < 10; i++)
                arr[i] += power * a * pow(10, power - 1);
        }
        for (int i = 1; i < a; i++)
            arr[i] += pow(10, power);

        arr[a]++;
        cur[a]++;
        power--;
    }
}
int main() {
    scanf("%d", &N);
    cnt(N);
    for (int i = 0; i < 10; i++)
        printf("%d ", arr[i]);
}