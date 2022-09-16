#include <stdio.h>
#include <math.h>
int T, n, sx, sy,ex,ey,x,y,r;
int start(int x, int y, int r) {
	if (pow(sx - x, 2) + pow(sy - y, 2) <= pow(r, 2))
		return 1;
	else
		return 0;
}
int end(int x, int y, int r) {
	if (pow(ex - x, 2) + pow(ey - y, 2) <= pow(r, 2))
		return 1;
	else
		return 0;
}
int main(void) {
	scanf("%d", &T);
	while (T--) {
		int cnt = 0;
		scanf("%d %d %d %d", &sx, &sy, &ex, &ey);
		scanf("%d", &n);
		while (n--) {
			scanf("%d %d %d", &x, &y, &r);
			if (start(x, y, r) ^ end(x, y, r))
				cnt++;
		}
		printf("%d\n", cnt);
	}
}