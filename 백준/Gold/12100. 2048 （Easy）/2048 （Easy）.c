#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int scan(int size, int board[20][20]);
void swapdown(int size, int board[20][20]);
void swapup(int size, int board[20][20]);
void swapleft(int size, int board[20][20]);
void swapright(int size, int board[20][20]);
void twozero(int size, int board[20][20], int count, int* max);
void show(int size, int board[20][20], int count);
void memcopy(int a[20][20], int b[20][20], int N);
int main() {
	int board[20][20], N, ans=0;
	scanf("%d", &N);
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			scanf("%d", &board[i][j]);
	twozero(N, board, 0, &ans);
	printf("%d\n", ans);
	return 0;
}
int scan(int size, int board[20][20]) {
	int max = 0;
	for (int i = 0; i < size; i++)
		for (int j = 0; j < size; j++)
			if (board[i][j] > max)
				max = board[i][j];
	return max;
}
void show(int size, int board[20][20], int count) {
	printf("\n");
	printf("c=%d\n", count);
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++)
			printf("%d ", board[i][j]);
		printf("\n");
	}
	printf("\n");
}
void twozero(int size, int board[20][20], int count, int* max) {
	//show(size, board, count);
	int cpboard[20][20];
	if (count >= 5) {
		int tmp = scan(size, board);//끝나고 정리
		*max = *max < tmp ? tmp : *max;
		//printf("max=%d\n", *max);
		return;
	}
	memcopy(board, cpboard, size);
	swapdown(size, cpboard);
	twozero(size, cpboard, count + 1, max);

	memcopy(board, cpboard, size);
	swapup(size, cpboard);
	twozero(size, cpboard, count + 1, max);

	memcopy(board, cpboard, size);
	swapright(size, cpboard);
	twozero(size, cpboard, count + 1, max);

	memcopy(board, cpboard, size);
	swapleft(size, cpboard);
	twozero(size, cpboard, count + 1, max);
	return;
}
void memcopy(int a[20][20], int b[20][20], int N) {
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			b[i][j] = a[i][j];
}


















void swapdown(int size, int board[20][20]) {
	for (int x = 0; x < size; x++) {
		int arr[20], len = 0;
		memset(arr, 0, sizeof(arr));
		for (int y = size - 1; y >= 0; y--) {//탐색
			if (board[y][x]) {
				if (len && arr[len - 1] == board[y][x]) arr[len - 1] *= -2;//합쳐짐
				else arr[len++] = board[y][x];//붙음
			}
		}
		for (int y = 0; y < size; y++)
			board[size - 1 - y][x] = abs(arr[y]);
	}
}
void swapup(int size, int board[20][20]) {
	for (int x = 0; x < size; x++) {
		int arr[20], len = 0;
		memset(arr, 0, sizeof(arr));
		for (int y = 0; y < size; y++) {//탐색
			if (board[y][x]) {
				if (len && arr[len - 1] == board[y][x]) arr[len - 1] *= -2;//합쳐짐
				else arr[len++] = board[y][x];//붙음
			}
		}
		for (int y = 0; y < size; y++)
			board[y][x] = abs(arr[y]);
	}
}
void swapleft(int size, int board[20][20]) {
	for (int x = 0; x < size; x++) {
		int arr[20], len = 0;
		memset(arr, 0, sizeof(arr));
		for (int y = 0; y < size; y++) {//탐색
			if (board[x][y]) {
				if (len && arr[len - 1] == board[x][y]) arr[len - 1] *= -2;//합쳐짐
				else arr[len++] = board[x][y];//붙음
			}
		}
		for (int y = 0; y < size; y++)
			board[x][y] = abs(arr[y]);
	}
}
void swapright(int size, int board[20][20]) {
	for (int x = 0; x < size; x++) {
		int arr[20], len = 0;
		memset(arr, 0, sizeof(arr));
		for (int y = size - 1; y >= 0; y--) {//탐색
			if (board[x][y]) {
				if (len && arr[len - 1] == board[x][y]) arr[len - 1] *= -2;//합쳐짐
				else arr[len++] = board[x][y];//붙음
			}
		}
		for (int y = 0; y < size; y++)
			board[x][size - 1 - y] = abs(arr[y]);
	}
}
