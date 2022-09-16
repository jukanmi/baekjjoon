#include <stdio.h>
#include <math.h>
int M, N, to[1000][1000],queue[2000000][2],len,st,A,try;
void show() {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++)
			printf("%d ", to[i][j]);
		printf("\n");
	}
	for (int i = st; i < len; i++)
		printf("%d %d\n", queue[i][0], queue[i][1]);
	printf("\n");
}
int check(){
	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++)
			if (!to[i][j])
				return 0;
	return 1;
}
void push(int a, int b) {
	queue[len][0] = a;
	queue[len++][1] = b;
	A = 1;
}
void move(int x, int y) {
	if (x < N - 1 && !to[x + 1][y]) {
		push(x + 1, y);
		to[x+1][y] = 1;
	}
	if (x > 0 && !to[x - 1][y]) {
		push(x - 1, y);
		to[x-1][y] = 1;
	}
	if (y < M-1 && !to[x][y + 1]) {
		push(x, y + 1);
		to[x][y+1] = 1;
	}
	if (y > 0 && !to[x][y - 1]) {
		push(x, y - 1);
		to[x][y-1] = 1;
	}
}

int main() 
{
	scanf("%d%d", &M, &N);
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++)
		{
			scanf("%d", &to[i][j]);
			if (to[i][j] == 1)
				push(i, j);
		}
	}
	push(-1, -1);
	int x, y;
	do {
		//show();

		A = 0;
		x = queue[st][0]; y = queue[st++][1];
		if (x == -1 && y == -1) {
			try++;
			push(-1, -1);
			continue;
		}
		move(x, y);
		//printf("da=%d\n", len - st);
	} while (len-st>1);
	if (check())
		printf("%d", try);
	else
		printf("-1");
}