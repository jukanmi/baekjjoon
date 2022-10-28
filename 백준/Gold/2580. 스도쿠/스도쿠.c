#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int check(int x, int y, int board[9][9], int tmp);
void func(int blank[81][2], int blen, int board[9][9], int maxblen);
void show(int board[9][9]);
int main() {
	int board[9][9], blank[81][2], maxblen = 0;
	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9; j++) {
			scanf("%d", &board[i][j]);
			if (!board[i][j])
				blank[maxblen][0] = i, blank[maxblen++][1] = j;
		}
	}
	func(blank, 0, board, maxblen);
	return 0;
}
void show(int board[9][9]) {
	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9; j++)
			printf("%d ", board[i][j]);
		printf("\n");
	}
}
int check(int x, int y, int board[9][9], int tmp) {
	for (int i = 0; i < 9; i++)
		if (board[x][i] == tmp || board[i][y] == tmp)
			return 0;
	int sx = (x / 3) * 3, sy = (y / 3) * 3;
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			if (board[sx + i][sy + j] == tmp)
				return 0;
		}
	}
	return 1;
}

void func(int blank[81][2], int blen, int board[9][9], int maxblen) {
	if (blen >= maxblen) {
		show(board);
		exit(0);
	}
	int x = blank[blen][0], y = blank[blen][1];
	for (int i = 1; i <= 9; i++) {
		if (check(x, y, board, i)) {
			board[x][y] = i;
			//show(board);
			func(blank, blen + 1, board, maxblen);
			board[x][y] = 0;
		}
	}

}