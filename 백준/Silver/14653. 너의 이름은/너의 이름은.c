#include <stdio.h>
int main() {
  int N,K,Q,ans[26]={1},len=1,R,be,first[26];
  char P;
  scanf("%d%d%d",&N,&K,&Q);
  for (int i=0;i<26;i++) first[i]=-1;
  for (int i=1;i<=K;i++){
    scanf("%d %c",&R,&P);
    if (i<Q){
      first[P-'A']=R;
      continue;
    }
    if (i==Q){
      if (R==0){
        printf("-1");
        return 0;
      }
      for (int i=0;i<N;i++){
        if (first[i]==R&&!ans[i]){
          ans[i]=1;
          len++;
        }
      }
    }
    if (!ans[P-'A']){
      ans[P-'A']=1;
      len++;
    }
  }
  if (len==N){
    printf("-1");
    return 0;
  }
  for (int i=1;i<N;i++)
    if (!ans[i])
      printf("%c ",i+'A');
}