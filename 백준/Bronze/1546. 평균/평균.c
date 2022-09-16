#include <stdio.h>
#include <stdlib.h>

int main() {
	float* k;
	int a;
	float max=0, total =0;
	scanf("%d", &a);
	k = (float*)malloc(sizeof(int) * a);
	for (int i = 0; i < a; i++) {
		scanf("%f", &k[i]);
	}
	
	for (int i = 0; i < a; i++) {
		if (k[i] > max)
			max = k[i];
	}

	for (int i = 0; i < a; i++)
		k[i] = ((float)k[i] / (float)max)* 100;
	
	for (int i = 0; i < a; i++)
		total += k[i];
	
	printf("%f", (float)total/(float)a);
	return 0;
}