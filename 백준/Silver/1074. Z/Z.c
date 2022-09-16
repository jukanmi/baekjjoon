#include <stdio.h>
#include <math.h>
//1074 Z[c][r] hyoseok님에게 무한한감사를
int num = 0,a;
int search(int n,int r,int c) {
	
	int pow2 = pow(2, n-1);
	if (n > 1) {
		if (r < pow2 && c < pow2) {
			return search(n - 1, r, c);
		}
		else if (r >= pow2 && c < pow2) {
			num+=2*(pow(pow2,2));
			return search(n - 1, r - pow2,c);
		}
		else if (r < pow2 && c >= pow2) {
			num += (pow(pow2,2));
			return search(n - 1, r, c - pow2);
		}
		else if (r >= pow2 && c >= pow2) {
			num += 3*(pow(pow2,2));
			return search(n - 1, r - pow2, c - pow2);
		}
	}
	else {
		if (r == 0 && c == 0) {
			a = num;
			return a;
		}
		else if (r == 1 && c == 0) {
			a = num + 2;
			return a;
		}
		else if (r == 0 && c == 1) {
			a = num + 1;
			return a;
		}
		else {
			a = num + 3;
			return a;
		}
	}
}
int main() {
	int N, R, C;
	scanf("%d %d %d", &N, &R, &C);
	printf("%d", search(N, R, C)); 
}