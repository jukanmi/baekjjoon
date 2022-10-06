#include <stdio.h>
int n, m, b,total,temp,depth[257],ans[2];
int search(int high) {
	int time = 0;
	int block = 0;//쓰이는 블럭의 개수
	for (int i = 0; i <=256; i++) {
		if (i < high) {
			time += depth[i] * (high - i);
			block += depth[i] * (high - i);
		}
		else if (i > high) {
			time += depth[i] * (i - high) * 2;
			block -= depth[i] * (i-high);
		}
	}
	//printf("t,b=%d,%d\n", time, block);
	if (block > b)
		return -1;
	else
		return time;
}
int main() {
	scanf("%d %d %d", &n, &m, &b);//3
	for (int i = 0; i < n*m; i++) {
		scanf("%d", &temp);
		depth[temp]++;
	}//500*500*2
	ans[0] = 2000000000;
	for (int i = 0; i <= 256; i++) {
		temp = search(i);
		//printf("%d=%d\n", i, temp);
		if (temp == -1)
			break;
		if (temp <= ans[0]) {//ans=[시간,땅 높이]
			ans[0]=temp;
			ans[1] = i;
		}
	}
	printf("%d %d", ans[0], ans[1]);
	return 0;
}