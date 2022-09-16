#include <stdlib.h>
#include <stdio.h>
//인구이동
int N, L, rout[101][51], R, A[51][51],check,all,many,day,lock[50][50],z,visit[50][50];

void show() {//보여주기
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++)
			printf("%d ", A[i][j]);
		printf("\n");
	}
	
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++)
			printf("%d ", lock[i][j]);
		printf("\n");
	}
	
	printf("\n");
}

void move(int x, int y) {//백트래킹이용한 이동
	//printf("x,y=%d,%d\n", x, y);
	
	if (!visit[x][y]) {
		visit[x][y] = 1;
		all += A[x][y]; many++;
		lock[x][y] = 0;
		if (y < N - 1 && rout[2 * x][y] == 1) {
			move(x, y + 1);
			rout[2 * x][y] = 0;
		}
		if (y > 0 && rout[2 * x][y - 1] == 1) {
			move(x, y - 1);
			rout[2 * x][y - 1] = 0;
		}
		if (x < N - 1 && rout[2 * x + 1][y] == 1) {
			move(x + 1, y);
			rout[2 * x + 1][y] = 0;
		}
		if (x > 0 && rout[2 * (x - 1) + 1][y] == 1) {
			move(x - 1, y);
			rout[2 * (x - 1) + 1][y] = 0;
		}
	}
	else
		return;
}

void fill() {
	//printf("all=%d\n", all);
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			if (visit[i][j]) {
				A[i][j] = all / many+1000;
				lock[i][j] = 1;
				visit[i][j] = 0;
			}
}

void horiz(int n) {//가로줄 세트 저장
	for (int i = 0; i < N-1; i++) {
		if (abs(A[n][i] - A[n][i + 1]) <= R && abs(A[n][i] - A[n][i + 1]) >= L) {
			rout[2 * n][i] = 1;
			check = 1;
			lock[n][i] = 0;
		}
	}

}

void verti(int n) {//세로줄 세트 저장
	for (int i = 0; i < N; i++) {
		if (abs(A[n][i] - A[n+1][i]) <=R && abs(A[n+1][i] - A[n][i])>=L) {
			rout[2 * n + 1][i] = 1;
			lock[n][i] = 0;
			check = 1;
		}
	}
}
void m() {
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			if (A[i][j]>1000)
				A[i][j] -= 1000;
}
int main() {
	//입력
	scanf("%d %d %d", &N, &L, &R);

	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			scanf("%d", &A[i][j]);
	//printf("\n");

	//국경선이 안열릴떄까지 반복
	do {
		//초기화
		check = 0;
		lock[0][0] = 0;
		//rout채우기
		for (int i = 0; i < N-1; i++) {
			horiz(i);
			verti(i);
		}
		horiz(N-1);

		//길따라 이동하고 채우기 10000이상이면 확인한것
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				if (A[i][j] < 1000&&!lock[i][j]) {//1000이상 10000이하면 평균낸것
					all = 0; many = 0;
					z = 0;
					move(i, j);
					fill();
				}
			}
		}
		m();
		//show();
		day++;
		//getchar();
	} while (check);

	printf("%d", day - 1);

}
