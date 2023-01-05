#include <stdio.h>
int main() {
  int T,N;
  scanf("%d",&T);
  while (T--){
    int sum=0;
    scanf("%d",&N);
    for (int i=1;i<N;i++)
      if (N%i==0)
        sum+=i;
    if (sum<N)puts("Deficient");
    else if (sum>N)puts("Abundant");
    else puts("Perfect");
  }
}