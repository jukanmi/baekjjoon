#include <stdio.h>
int T, M, N, K,x,y,check,F[50][50];
void wasd(x,y) {
	F[x][y] = 0;
	if ((x<M-1)&&(F[x + 1][y] == 1))
		wasd(x + 1, y);
	if ((y < N - 1) && (F[x][y + 1] == 1))
		wasd(x, y + 1);
	if ((x > 0) && (F[x-1][y] == 1))
		wasd(x-1, y);
	if ((y>0) && (F[x][y - 1] == 1))
		wasd(x, y - 1);
}
int main() {
	scanf("%d", &T);
	while (T--) {
		check = 0;
		scanf("%d %d %d", &M, &N, &K);
		while (K--) {
			scanf("%d %d", &x, &y);
			F[x][y] = 1;
		}
		for (int i = 0; i < M; i++) {
			for (int j = 0; j < N; j++) {
				if (F[i][j] == 1) {
					check++;
					wasd(i, j,&F);
				}
			}  
		}
		printf("%d\n", check);
	}
}