#include <stdio.h>
char pm[100000001];
int queue[100001],doma[100001],len,start=1;
int n,ch,b;
void push(int x) {
	queue[++len] = x;
}
void pop() {
	len--;
}
int main() {
	queue[0] = 10;
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &doma[i]);
		if (doma[i] == n)
			ch = i;
	}

	for (int i = 1; i <= n; i++) {
		pm[b++] = 43;
		push(i);
		ch = 0;

		while (ch == 0) //ch==0:한번 더 할수있을지 확인
		{
			if (doma[start] == queue[len]) {
				start++;
				pm[b++] = 45;
				pop();

			}
			else
				ch = 1;
		}

	}
	ch = 0;
	for (int i = 0; pm[i] != NULL; i++)
		if (pm[i] == 45)
			ch++;
	if (ch==n){
		for (int i = 0; pm[i] != NULL; i++) {
			printf("%c\n", pm[i]);
		}
	}
	else {
		printf("NO");
	}
}