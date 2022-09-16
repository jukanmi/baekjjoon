#include <stdio.h>
int N, M, pack[51], one[51],result;
float pack_one[51],one_min=100000,pack_min=100000;
int main() {
	scanf("%d %d", &N, &M);
	for (int i=0;i<M;i++) {
		scanf("%d %d", &pack[i], &one[i]);
	}
	for (int i = 0; i < M; i++) {
		pack_one[i] = (float)pack[i] / 6;
	}
	for (int i = 0; i < M; i++) {
		if (one[i] < one_min) one_min = one[i];
		if (pack_one[i] < pack_min) pack_min = pack_one[i];
	}

	if (pack_min < one_min) {
		result = pack_min * 6 * (N / 6);
		N -= 6 * (N / 6);
	}
	else {
		result = one_min * N;
		printf("%d", result);
		return 0;
	}

	result += pack_min * 6 < one_min * N ? pack_min * 6 : one_min * N;
	printf("%d", result);
}