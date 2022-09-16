#include <stdio.h>
int n, a[500001], b[500001],ans[500001],len=-1;
int main() {
	scanf("%d", &n);

	for (int i = 0; i < n; i++) {
		scanf("%d", &a[i]);
		b[++len] = i;
		while (len>=1) {
			if (a[b[len - 1]] > a[b[len]]) {
				ans[i] = b[len - 1]+1;
				break;
			}
			else {
				b[len - 1] = b[len];
				len--;
				b[len + 1] = 0;
			}
		}
	}
	for (int i = 0; i < n; i++)
		printf("%d ", ans[i]);
	return 0;
}
