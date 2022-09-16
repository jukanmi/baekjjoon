#include <stdio.h>
#include <stdlib.h>
int N, p[100000], m[100000], P, M, ans[3], anss[3], mid, dra;

int main() {
	anss[2] = 2000000001;
	scanf("%d", &N);

	for (int i = 0; i < N; i++) {
		scanf("%d", &dra);
		if (dra > 0)//음수 양수 구분
			p[P++] = dra;
		else
			m[M++] = dra;
	}
	for (int i = 0; i < M&&P; i++) {//음수 하나당 이분탐색
		int low = 0, high = P - 1;
		//printf("l,h=%d %d\n", low, high);
		while (low < high - 1) {
			mid = (low + high) / 2;
			if (m[i] + p[mid] > 0) high = mid;
			else if (m[i] + p[mid] < 0) low = mid;
			else {//0이면 바로 출력
				printf("%d %d", m[i], p[mid]);
				return 0;
			}
			//printf("%d %d\n", m[i], p[mid]);
		}
		ans[0] = m[i];
		if (abs(m[i] + p[low]) >= abs(m[i] + p[high])) {
			ans[1] = p[high]; ans[2] = abs(m[i] + p[high]);
		}
		else {
			ans[1] = p[low]; ans[2] = abs(m[i] + p[low]);
		}
		if (anss[2] > ans[2]) {
			anss[0] = ans[0]; anss[1] = ans[1]; anss[2] = ans[2];
		}
	}
	//printf("%d %d\n", m[M - 2] + m[M - 1], p[0] + p[1]);
	if (P >= 2 && anss[2] >= p[0] + p[1]) {//둘다 양수 일때
		anss[2] = p[0] + p[1]; anss[0] = p[0]; anss[1] = p[1];
	}
	if (M >= 2 && anss[2] >= -1 * (m[M - 2] + m[M - 1])) {//둘다 음수 일때
		anss[0] = m[M - 2]; anss[1] = m[M - 1];
	}
	printf("%d %d", anss[0], anss[1]);
}
/*
3
-100000 1 10000000
*/