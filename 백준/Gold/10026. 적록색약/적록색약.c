#include <stdio.h>
int N, area[100][100], red[10000][2], redlen;
char tmp;
void input() {
	scanf("%d\n", &N);
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			scanf("%c", &tmp);
			switch (tmp)
			{
			case 'R':area[i][j] = 1; red[redlen][0] = i; red[redlen++][1] = j; break;
			case 'G':area[i][j] = 2; break;
			case 'B':area[i][j] = 3; break;
			default:
				break;
			}
		}
		getchar();
	}
}
void dfs(int x, int y, int color) {
	area[x][y] *= -1;
	if (x > 0 && area[x - 1][y] == color) dfs(x - 1, y, color);
	if (y > 0 && area[x][y - 1] == color) dfs(x, y - 1, color);
	if (x < N - 1 && area[x + 1][y] == color) dfs(x + 1, y, color);
	if (y < N - 1 && area[x][y + 1] == color) dfs(x, y + 1, color);
}
void dfsr(int x, int y) {
	area[x][y] = -1;
	if (x > 0 && area[x - 1][y] == -2) dfsr(x - 1, y);
	if (y > 0 && area[x][y - 1] == -2) dfsr(x, y - 1);
	if (x < N - 1 && area[x + 1][y] == -2) dfsr(x + 1, y);
	if (y < N - 1 && area[x][y + 1] == -2) dfsr(x, y + 1);
}
int check1() {
	int area_num = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (area[i][j] > 0) {
				area_num++;
				dfs(i, j, area[i][j]);
			}
		}
	}
	return area_num;
}
void green_to_red() {
	for (int i = 0; i < redlen; i++)
		dfsr(red[i][0], red[i][1]);
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			area[i][j] *= -1;
}
void view() {
	printf("\nview\n");
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++)
			printf("%d ", area[i][j]);
		printf("\n");
	}
	printf("\n\n");
}
int main() {
	input();
	printf("%d ", check1());
	green_to_red();
	printf("%d\n", check1());
	return 0;
}