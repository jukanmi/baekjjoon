#include <stdio.h>//크기 순으로 정리한다 생각
int T, N,cas[10001][3];
int main(void) {
	scanf("%d", &T);
	cas[1][0] = 1;//1
	cas[2][0] = 1;//1 1
	cas[2][1] = 1;//2
	cas[3][0] = 1;//1 1 1
	cas[3][1] = 1;//1 2
	cas[3][2] = 1;//3
	//이전거보다 크면 더하기
	for (int i = 4; i < 10001; i++) {
		cas[i][0]=cas[i-1][0];//1을 추가하려면 끝이 1일때만 추가가능
		cas[i][1]=cas[i-2][0]+cas[i-2][1];//2를 추가하려면 끝이 1,2일때만 추가가능
		cas[i][2]=cas[i-3][0]+cas[i-3][1]+cas[i-3][2];//3을 추가하려면 끝이 1,2,3일때만 추가가능
		//cas[4][2]=cas[3][0]+cas[2][1]+cas[1][2]
	}
	while (T--) {
		scanf("%d", &N);
		int ans=0;
		for (int i=0;i<3;i++)
			ans+=cas[N][i];
		printf("%d\n",ans);
	}
}