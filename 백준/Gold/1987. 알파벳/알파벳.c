#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//1987 비트마스킹을 이용한 DFS
int R, C, ans = 0;
struct save
{
	int count;
	long long S;
};
int check(int x, int y, long long sa, int a[20][20]) {
	if (0 <= x && x < C && 0 <= y && y < R)
		return !(sa & (1<<a[y][x]));
	else
		return 0;
}
struct save dfs(struct save sav, int a[20][20], int x, int y) {
	sav.S |= 1 << a[y][x];
	sav.count++;
	if (check(x, y + 1, sav.S, a))
		dfs(sav, a, x, y + 1);
	if (check(x, y - 1, sav.S, a))
		dfs(sav, a, x, y - 1);
	if (check(x + 1, y, sav.S, a))
		dfs(sav, a, x + 1, y);
	if (check(x - 1, y, sav.S, a))
		dfs(sav, a, x - 1, y);
	ans = ans < sav.count ? sav.count : ans;
	//printf("%d\n", ans);
}

int main() {
	struct save s = { 0,0 };
	int a[20][20];
	char tmp;
	scanf("%d %d\n", &R, &C);
	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			scanf("%c", &tmp);
			a[i][j] = tmp-65;
		}
		getchar();
	}
	dfs(s, a, 0, 0);
	printf("%d", ans);
	return 0;
}
