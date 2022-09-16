#include <stdio.h>

int N,fam[2500],friend,d,ham[50],manyfri[50];
char fri[50][50];

void friappend(int n) {
	for (int j = 0; j < N; j++) {
		if (fri[n][j] == 89) {
			fam[friend++] = j;
		}
	}
}

void check(int n) {
	for (int i = 0; i < friend; i++) {
		if (fam[i]!=-1)
			ham[fam[i]] = 1;
	}
	for (int i = 0; i < N; i++) {
		if (ham[i]!=0&&i!=n) {
			manyfri[n]++;
		}
	}
}

int main(void) {
	scanf("%d", &N);
	for (int i = 0; i < N; i++)
		scanf("%s", fri[i]);
	/*
	for (int i = 0; i < N; i++) {
		printf("%d:", i);
		for (int j = 0; j < N; j++)
			if (fri[i][j] == 89)
				printf(" %d", j);
		printf("\n");
	}
	*/
	for (int i = 0; i < N; i++) {
		friend = 0;
		friappend(i);
		fam[friend++]=-1;
		for (int j = 0; fam[j] != -1; j++) {
			friappend(fam[j]);
		}
		check(i);
		/*
		printf("after\n");
		for (int a = 0; a < friend; a++)
			printf("%d ", fam[a]);
		printf("\n");
		printf("ham:\n");
		for (int a = 0; a < N; a++)
			printf("%d ", ham[a]);
		printf("\n");
		*/
		for (int j = 0; j < N; j++)
			ham[j] = 0;
		while (friend--)
			fam[friend] = 0;
	}
	/*
	for (int i = 0; i < N; i++)
		printf("%d ", manyfri[i]);
	*/
	int max = 0;
	for (int i = 0; i < N; i++)
		if (max < manyfri[i])
			max = manyfri[i];
	printf("%d", max);
}