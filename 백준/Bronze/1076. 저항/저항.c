#include <stdio.h>
#include <string.h>
#include <math.h>
#define ll long long
int main() {
	char s[7];
     ll ans=0;
    for (int i=0;i<2;i++){
        ans*=10;
        scanf("%s", s);
        if (s[0]=='b'&&s[3]=='w') ans+=1;
        else if (s[0]=='r') ans+=2;
        else if (s[0]=='o') ans+=3;
        else if (s[0]=='y') ans+=4;
        else if (s[0]=='g'&&s[3]=='e') ans+=5;
        else if (s[0]=='b'&&s[3]=='e') ans+=6;
        else if (s[0]=='v') ans+=7;
        else if (s[0]=='g') ans+=8;
        else if (s[0]=='w') ans+=9;
    }
    scanf("%s",s);
    if (s[0]=='b'&&s[3]=='w') ans*=10;
    else if (s[0]=='r') ans*=100;
    else if (s[0]=='o') ans*=1000;
    else if (s[0]=='y') ans*=10000;
    else if (s[0]=='g'&&s[3]=='e') ans*=100000;
    else if (s[0]=='b'&&s[3]=='e') ans*=1000000;
    else if (s[0]=='v') ans*=10000000;
    else if (s[0]=='g') ans*=100000000;
    else if (s[0]=='w') ans*=1000000000;
    printf("%lld",ans);
}