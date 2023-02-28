#include <stdio.h>

int main() {
	char w;
	while (1){
		scanf("%c", &w);
		if (w==10) break;
		if (w>=97) printf("%c",w-32);
		else printf("%c",w+32);
	}
	return 0;
}
