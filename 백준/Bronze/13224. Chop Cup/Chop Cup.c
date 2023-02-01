#include <stdio.h>
#include <string.h>
int logic(int curr, char c){
	switch (c)
	{
	case 'A':
		if (curr==1) return 2;
		if (curr==2) return 1;
		return curr;
	case 'B':
		if (curr==2) return 3;
		if (curr==3) return 2;
		return curr;
	case 'C':
		if (curr==1) return 3;
		if (curr==3) return 1;
		return curr;
	default:
		return curr;
	}
}
int main(){
	int ans=1;
	char s[52];
	scanf("%s",s);
	int len=strlen(s);
	for (int i=0;i<len;i++)
		ans=logic(ans,s[i]);
	printf("%d\n",ans);
}