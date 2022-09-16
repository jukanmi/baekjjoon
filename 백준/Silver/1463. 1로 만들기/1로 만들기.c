#include <stdio.h>
//1463
int X,A[1000001],check;
int m(int a, int b) {
	return a > b ? b : a;
}
int main(){
	scanf("%d", &X);
	for (int i = 2; i <= X+1; i++) {
		check = A[i - 1];
		if (i % 3 == 0)
			check = m(A[i / 3], check);
		if (i % 2 == 0)
			check = m(A[i / 2], check);
		A[i] = check+1;
		
	}
	printf("%d",A[X]);
}