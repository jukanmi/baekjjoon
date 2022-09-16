#include <stdio.h>
#include <string.h>
#include <math.h>
int N;
int alpha[26],ans=0;
char temp[9];
int ma();
int po(int n){
    int re=1;
    while (n--){
        re*=10;
    }
    return re;
}
int main(){
    scanf("%d\n",&N);
    for (int i=0;i<N;i++){
        scanf("%s",temp);
        int len = strlen(temp);
        for (int j=0;j<len;j++){
            alpha[temp[j]-65]+=po(len-j-1);
            //printf("%d %d\n",alpha[0],po(len-j-1));
        }
    }

    for (int i=9;i>0;i--){
        int Max=ma();
        if (alpha[Max]==0) break;
        ans+=i*alpha[Max];
        alpha[Max]=0;
    }
    printf("%d\n",ans);
}
int ma(){
    int M[2]={0,0};
    for (int i=0;i<26;i++){
        if (M[0]<alpha[i]){
            M[0]=alpha[i];
            M[1]=i;
        }
    }
    return M[1];
}