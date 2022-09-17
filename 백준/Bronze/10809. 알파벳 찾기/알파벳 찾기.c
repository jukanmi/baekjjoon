#include <stdio.h>
char a[101];
int z[101],p;
int main() {
	for (int i = 0; i < 100; i++) z[i]--;
	scanf("%s", &a);
	for (int i = 0; a[i] != NULL; i++) {
		if (z[a[i] - 97]==-1)
			z[a[i] - 97] = i;
	}
	for (int i = 0;i<26 ; i++) {
		printf("%d ", z[i]);
	}
}