#include <stdio.h>
#include <stdlib.h>
#include <math.h>
int n, m, min=64, w,b;
char s[50][51];

int main() {
	scanf("%d %d", &n, &m);
	for (int i = 0; i < n; i++) {
		scanf("%s", s[i]);
	}
	for (int i = 0; i < n - 7; i++) {
		for (int j = 0; j < m - 7; j++) {
			w = 0, b = 0;
			for (int x = 0; x < 8; x++) {
				for (int y = 0; y < 8; y++) {
					if (s[i + x][j + y] == 'B')
						((x + y) % 2 == 0) ? w++ : b++;
					else
						((x + y) % 2 == 0) ? b++ : w++;
				}
			}

			if (min > w)
				min = w;
			if (min > b)
				min = b;
		}
		}
	printf("%d", min);
	return 0;
	}