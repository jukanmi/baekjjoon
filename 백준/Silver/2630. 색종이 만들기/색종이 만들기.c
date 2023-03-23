#include <stdio.h>
int color[130][130],blen,wlen;
void search(int n,int sx,int sy) {
    int len=0;
	for (int i=0;i<n;i++) 
        for (int j = 0; j < n; j++)
            if (color[i+sx][j+sy])
                len++;
    if (len == 0) {
        wlen++;
        return;
    }
    if (len == n*n){
        blen++;
        return;
    }
    search(n/2,sx,sy);
    search(n/2,sx,sy+n/2);
    search(n/2,sx+n/2,sy);
    search(n/2,sx+n/2,sy+n/2);
}
int main() {
	int N;
    
	scanf("%d", &N);
    for (int i=0;i < N;i++)
        for (int j=0;j < N;j++)
            scanf("%d", &color[i][j]);
    search(N,0,0);
	printf("%d\n%d\n", wlen, blen);
    return 0;
}