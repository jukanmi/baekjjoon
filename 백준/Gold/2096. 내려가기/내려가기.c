#include <stdio.h>
int dpmax[2][3], input[3],dpmin[2][3];
int max(int a, int b) { return a > b ? a : b; }
int min(int a, int b) { return a < b ? a : b; }
int max3(int a, int b, int c) { return max(max(a, b), c); }
int min3(int a, int b, int c) { return min(min(a, c), b); }
int main() {
	int N;
	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		scanf("%d %d %d", &input[0],&input[1],&input[2]);
		//최댓값
		dpmax[i % 2][0] = max(dpmax[!(i % 2)][0], dpmax[!(i % 2)][1])+input[0];
		dpmax[i % 2][1] = max3(dpmax[!(i % 2)][0], dpmax[!(i % 2)][1], dpmax[!(i % 2)][2]) + input[1];
		dpmax[i % 2][2] = max(dpmax[!(i % 2)][1], dpmax[!(i % 2)][2]) + input[2];
		//최솟값
		dpmin[i % 2][0] = min(dpmin[!(i % 2)][0], dpmin[!(i % 2)][1]) + input[0];
		dpmin[i % 2][1] = min3(dpmin[!(i % 2)][0], dpmin[!(i % 2)][1], dpmin[!(i % 2)][2]) + input[1];
		dpmin[i % 2][2] = min(dpmin[!(i % 2)][1], dpmin[!(i % 2)][2]) + input[2];
		//printf("m=%d %d %d\n", dpmax[i % 2][0], dpmax[i % 2][1], dpmax[i % 2][2]);
		//printf("n=%d %d %d\n", dpmin[i % 2][0], dpmin[i % 2][1], dpmin[i % 2][2]);
	}
	
	printf("%d ", max3(dpmax[!(N % 2)][0], dpmax[!(N % 2)][1], dpmax[!(N % 2)][2]));
	printf("%d ", min3(dpmin[!(N % 2)][0], dpmin[!(N % 2)][1], dpmin[!(N % 2)][2]));
}