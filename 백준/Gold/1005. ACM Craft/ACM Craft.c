#include <stdio.h>
int T, N, K, star[1001][1001], sec[1001], prebuild[1001], max, num, a;
void reset() {//정리x
	for (int i = 1; i <= N; i++) {
		star[i][0] = 0;
	}
	for (int i = 1; i <= N; i++)
		prebuild[i] = -1;
}

int main() {
	scanf("%d", &T);
	while (T--) {
		scanf("%d%d", &N, &K);
		reset();
		for (int i = 1; i <= N; i++)
			scanf("%d", &sec[i]);
		int x, y;
		for (int i=0;i<K;i++) {
			scanf("%d %d", &x, &y);
			star[y][star[y][0]++ + 1] = x;
		}
		scanf("%d", &num);
		//printf("pre=%d\n", prebuild[1]);
		while (prebuild[num]==-1) {
			for (int i = 1; i <= N; i++) {
				max = 0;
				for (int j = 1; j <= star[i][0]; j++) {
					//printf("pree=%d\n",star[i][j]);
					if (prebuild[star[i][j]]!=-1) {
						if (max < prebuild[star[i][j]]) {
							max = prebuild[star[i][j]];
						}
					}
					else {
						//printf("break\n");
						a = 1;
						break;

					}
				}
				//printf("i=%d %d\n", i,a);
				if (a != 1) {
					prebuild[i] = max + sec[i];
				}
				a = 0;
			}
			/*
			printf("pre=");
			for (int i = 1; i <= N; i++)
				printf("%d ", prebuild[i]);
				*/
				
		}
		printf("%d\n", prebuild[num]);
	}
}