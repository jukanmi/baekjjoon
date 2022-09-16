#include <stdio.h>
#include <math.h>
int arr[50][5];
int r1, c1, r2, c2;
int a = 1,b=1;
int m(int a, int b, int c, int d) {
	a = abs(a); b = abs(b); c = abs(c); d = abs(d);
	a = a > b ? a : b;
	a = a > c ? a : c;
	return a > d ? a : d;
}
int len(int n) {
	int num = 0;
	while (n) {
		num++;
		n /= 10;
	}
	return num;
}
int main() {
	scanf("%d%d%d%d", &r1, &c1, &r2, &c2);
	int max = m(r1, r2, c1, c2)+1;
	int x = 0, y = 0;
	while (max--) {
		for (int i = 1; i <= b; i++) {
			a++;
			if (r1 <= x && x <= r2 && c1 <= y + i && y + i <= c2)
				arr[x - r1][y + i - c1] = a;
		}
		y += b;
		for (int i = 1; i <= b; i++) {
			a++;
			if (r1 <= x - i && x - i <= r2 && c1 <= y && y <= c2)
				arr[x - i - r1][y - c1] = a;
		}
		x -= b++;
		for (int i = 1; i <= b; i++) {
			a++;
			if (r1 <= x && x <= r2 && c1 <= y-i && y-i <= c2)
				arr[x - r1][y - i - c1] = a;
		}
		y -= b;
		for (int i = 1; i <= b; i++) {
			a++;
			if (r1 <= x + i && x + i <= r2 && c1 <= y && y <= c2)
				arr[x + i - r1][y - c1] = a;
		}
		x += b++;
	}
	max = m(len(arr[0][0]), len(arr[0][c2-c1]), len(arr[r2-r1][0]), len(arr[r2-r1][c2 -c1]));
	//printf("max=%d %d %d %d\n", (arr[0][0]), (arr[0][c2-c1]), (arr[r2-r1][0]), (arr[r2-r1][c2 - c1]));
	; if (r1 <= 0 && 0 <= r2 && c1 <= 0 && 0 <= c2)
		arr[-r1][-c1] = 1;
	for (int i = 0; i <= r2-r1; i++) {
		for (int j = 0; j <= c2-c1; j++) {
			for (int z = len(arr[i][j]); z < max; z++)
				printf(" ");
			printf("%d ", arr[i][j]);
		}
		printf("\n");
	}
}