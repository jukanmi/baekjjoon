#include <stdio.h>

int main() {
	int E, S, M;
	scanf("%d %d %d", &E, &S, &M);
	for (int i=S;i<8000;){
		if (i % 15 + !(i % 15) * 15 == E && i % 19 + !(i % 19) * 19 == M) {
			printf("%d", i);
			return 0;
		}
		i += 28;
	}
	

}