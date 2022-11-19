#include <stdio.h>
#include <string.h>
int main() {
	char s[102];
	int c[4];
	while (NULL!=fgets(s,102,stdin)){
		c[0]=0,c[1]=0,c[2]=0,c[3]=0;
		int len=strlen(s)-1;
		for (int i=0;i<len;i++){
			if ('a'<=s[i]&&s[i]<='z') c[0]++;
			else if ('A'<=s[i]&&s[i]<='Z') c[1]++;
			else if ('0'<=s[i]&&s[i]<='9') c[2]++;
			else if (s[i]==' ') c[3]++;
		}
		printf("%d %d %d %d\n",c[0],c[1],c[2],c[3]);
	}	
	return 0;
}
