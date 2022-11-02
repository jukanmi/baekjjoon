#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#define MAX 2147483647

double abstor(int x, int y);
void tracking(int N, int point[20][2], double* min, int F, int visit, int end);
int main() {
	int T, N, point[20][2];
	scanf("%d", &T);
	while (T--) {
		double min = MAX;
		scanf("%d", &N);
		for (int i = 0; i < N; i++) scanf("%d %d", &point[i][0], &point[i][1]);
		tracking(N, point, &min, 0, 0, -1);
		printf("%.12lf\n", min);
	}
}
double abstor(int x, int y) {
	return sqrt(pow(x, 2) + pow(y, 2));
}
/*
N:백터매칭의 갯수
vec: 저장된 백터
*min: 가장 작은 백터매칭 저장하는곳
F: 백트래킹 숫자
visit: 사용한 백터저장 (비트마스킹)
end: 마지막번호
*/
void tracking(int N, int point[20][2], double* min, int F, int visit, int end) {
	if (F == N / 2) {
		int sum[2] = { 0 };
		for (int i = 0; i < N; i++) {
			if (visit & 1)
				sum[0] += point[i][0], sum[1] += point[i][1];
			else
				sum[0] -= point[i][0], sum[1] -= point[i][1];
			visit >>= 1;
		}
		double tmp = abstor(sum[0], sum[1]);
		if (tmp < *min)
			*min = tmp;
		return;
	}
	for (int i = end + 1; i < N; i++) {
		if (!(visit & (1 << i))) {
			tracking(N, point, min, F + 1, visit | (1 << i), i);
		}
	}
	return;
}