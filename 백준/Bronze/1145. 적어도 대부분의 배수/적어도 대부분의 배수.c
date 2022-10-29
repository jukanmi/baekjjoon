#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAX 2147483647
int gcd(int a, int b){
	if (!b) return a;
	return gcd(b,a%b);
}
int lcm(int a,int b){
	return a*b/gcd(a,b);
}
int main(){
	int n[5],min=MAX;
	for (int i=0;i<5;i++)
		scanf("%d",&n[i]);
	for (int a=0;a<3;a++)
		for (int b=a+1;b<4;b++)
			for (int c=b+1;c<5;c++)
				min= min>lcm(lcm(n[a],n[b]),n[c])?lcm(lcm(n[a],n[b]),n[c]):min;
	printf("%d",min);
}