#include <stdio.h>
#include <math.h>
int N,Tr=0,sx=0,sy=0;
char xs[65][65];
int QT(int n,int x,int y);
int main() {
	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		scanf("%s", &xs[i]);
	}

	QT(N, 0, 0);
}
int QT(int n,int x,int y) {

	//printf(" n%d ", n);

	Tr = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			Tr += xs[i+x][j+y]-48;
		}
	}
	if (Tr == pow(n, 2)) {
		printf("1");
	}
	else if (Tr == 0) {
		printf("0");
	}

	else {
		printf("(");
		QT(n / 2, x, y);
		y += n/ 2;
		QT(n / 2, x, y);
		y -= n / 2;
		x += n/ 2;
		QT(n / 2, x, y);
		y += n / 2;
		QT(n / 2, x, y);
		printf(")");

	}

}