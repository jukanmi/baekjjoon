#include <stdio.h>
int M, N, H, to[100][100][100], queue[2][2000000][3], len[2], tt = -1;
void show() {
	for (int i = 0; i < H;i++) {
		for (int j = 0; j < N; j++) {
			for (int k = 0; k < M; k++) {
				printf("%2d ", to[i][j][k]);
			}
			printf("\n");
		}
		printf("\n\n");
	}
	printf("\n");
}
int check() {
	for (int k = 0; k < H; k++)
		for (int i = 0; i < N; i++)
			for (int j = 0; j < M; j++)
				if (!to[k][i][j])
					return 0;
	return 1;
}
void push(int a, int b, int c, int AB) {//높 세 가
	queue[AB][len[AB]][0] = a;
	queue[AB][len[AB]][1] = b;
	queue[AB][len[AB]++][2] = c;//높 세 가
}
void move(int lo[], int AB) {
	if (lo[0] < H - 1 && !to[lo[0]+1][lo[1]][lo[2]]) {
		push(lo[0] + 1, lo[1], lo[2], AB);
		to[lo[0] + 1][lo[1]][lo[2]] = 1;
	}
	if (lo[0] > 0 && !to[lo[0]-1][lo[1]][lo[2]]) {
		push(lo[0] - 1, lo[1], lo[2], AB);
		to[lo[0] - 1][lo[1]][lo[2]] = 1;
	}
	if (lo[1] < N - 1 && !to[lo[0]][lo[1] + 1][lo[2]]) {
		push(lo[0], lo[1] + 1, lo[2], AB);
		to[lo[0]][lo[1] + 1][lo[2]] = 1;
	}
	if (lo[1] > 0 && !to[lo[0]][lo[1] - 1][lo[2]]) {
		push(lo[0], lo[1] - 1, lo[2], AB);
		to[lo[0]][lo[1] - 1][lo[2]] = 1;
	}
	if (lo[2] < M - 1 && !to[lo[0]][lo[1]][lo[2]+1]) {
		push(lo[0], lo[1], lo[2] + 1, AB);
		to[lo[0]][lo[1]][lo[2]+1] = 1;
	}
	if (lo[2] > 0 && !to[lo[0]][lo[1]][lo[2]-1]) {
		push(lo[0], lo[1], lo[2] - 1, AB);
		to[lo[0]][lo[1]][lo[2] - 1] = 1;
	}
}

int main()
{
	scanf("%d%d%d", &M, &N, &H);
	for (int i = 0; i < H; i++) {
		for (int j = 0; j < N; j++) {
			for (int k = 0; k < M; k++) {
				scanf("%d", &to[i][j][k]);
				if (to[i][j][k] == 1)
					push(i, j, k, 0);//높 세 가
			}
		}
	}
	for (int i = 0; i < 1000000000; i++) {
		if (len[i % 2] == 0) break;
		tt++;
		len[!(i % 2)] = 0;
		for (int j=0;j<len[i%2];j++)
			move(queue[i % 2][j], !(i % 2));
		//show();
	}
	if (check()) printf("%d", tt);
	else printf("-1");

}