#include <stdio.h>
#include <stdlib.h>
#include<string.h>
int N, M, knowman[51], festiman[50][51], map[51][51], chain[51],ans;
void dfs(int n) {
	if (chain[n] == 0) {
		chain[n] = 1;
		for (int i = 1; i <= 50; i++)
			if (map[n][i])
				dfs(i);
	}
}
int main() {
	scanf("%d %d", &N, &M);
	scanf("%d", &knowman[0]);
	for (int i = 1; i <= knowman[0]; i++)
		scanf("%d", &knowman[i]);
	for (int i = 0; i < M; i++) {
		scanf("%d", &festiman[i][0]);
		for (int j = 1; j <= festiman[i][0]; j++)
			scanf("%d", &festiman[i][j]);
	}
	for (int i = 0; i < M; i++) {
		for (int x = 1; x < festiman[i][0]; x++) {
			for (int y = x + 1; y <= festiman[i][0]; y++) {
				map[festiman[i][x]][festiman[i][y]] = 1;
				map[festiman[i][y]][festiman[i][x]] = 1;
			}
		}
	}
	for (int i = 1; i <= knowman[0]; i++) {
		dfs(knowman[i]);
	}
	for (int i = 0; i < M; i++) {
		for (int j = 1; j <= festiman[i][0]; j++) {
			if (chain[festiman[i][j]]) {
				ans++;
				break;
			}
		}
	}
	printf("%d", M-ans);
}

