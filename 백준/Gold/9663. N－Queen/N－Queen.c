#include <stdio.h>
int q[15][2],N,len,set;
int check(int x, int y) {
	for (int i = 0; i < len; i++) {
		if (q[i][0] == x || q[i][1] == y)
			return 0;
		if (q[i][0] - x == q[i][1] - y)
			return 0;
		if (x + y == q[i][0] + q[i][1])
			return 0;
	}
	return 1;
}
void back(x) {
	for (int y = 0; y < N; y++) {
		if (check(x, y)) {
			q[len][0] = x;
			q[len++][1] = y;
			if (len == N) {
				set++;
				len--;
				return 0;
			}
			else {
				back(x + 1);
				len--;
			}
		
		}
	}
	
}
int main() {
	scanf("%d", &N);
	back(0);
	printf("%d", set);
}