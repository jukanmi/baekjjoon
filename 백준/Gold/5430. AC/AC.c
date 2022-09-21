#include <stdio.h>
#include <string.h>
int t, n, Start, End, x[100000], R;
char p[100001];
int main() {
	scanf("%d", &t);
	for (int i = 0; i < t; i++) {
		R = 0;
		scanf("%s", p);
		int len = strlen(p);
		scanf("%d\n[", &n);
		for (int j = 0; j < n - 1; j++) {
			scanf("%d,", &x[j]);
		}
		if (n > 0) scanf("%d]", &x[n - 1]);
		else { scanf("]"); }
		Start = 0; End = n - 1;
		for (int j = 0; j < len; j++) {
			if (p[j] == 'R') R = !R;
			else {
				if (End - Start<0) { printf("error\n"); R = -1; break; }
				if (R) End--;
				else Start++;
			}
		}
		if (End - Start < 0 &&R!=-1) {
			printf("[]\n");
			continue;
		}
		if (R == 0) {
			printf("[%d", x[Start]);
			for (int r = Start + 1; r <= End; r++)
				printf(",%d", x[r]);
			printf("]\n");
		}
		else if (R == 1) {
			printf("[%d", x[End]);
			for (int r = End - 1; r >= Start; r--)
				printf(",%d", x[r]);
			printf("]\n");
		}
	}
}