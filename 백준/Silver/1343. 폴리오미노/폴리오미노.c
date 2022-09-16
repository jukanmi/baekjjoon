#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>
char N[51];
int X;
int main() {
	scanf("%s", N);
	for (int i = 0; i < strlen(N); i++) {
		if (N[i] == 88) {
			X++;
		}
		else {
			if (X == 1 || X == 3) {
				printf("-1");
				return 0;
			}
			else if (X == 2)
				for (int z = 1; z <= 2; z++)
					N[i - z] = 66;
			X = 0;
		}
		if (X >= 4) {
			for (int z = 0; z < 4; z++)
				N[i - z] = 65;
			X = 0;
		}
	}
	if (X == 1 || X == 3) {
		printf("-1");
		return 0;
	}
	else if (X == 2)
		for (int z = 1; z <= 2; z++)
			N[strlen(N) - z] = 66;
	for (int i = 0; i < strlen(N); i++)
		printf("%c", N[i]);
}