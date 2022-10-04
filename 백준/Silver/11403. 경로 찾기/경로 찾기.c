#include <stdio.h>
int N;
void dfs(int first,int via, int Root[][101],int cpy[][101]){
    for (int i=0;i<N;i++){
        if (Root[via][i]&&!cpy[first][i]){
            cpy[first][i]=1;
            dfs(first,i,Root,cpy);
        }
    }
}
int main() {
    int Root[101][101],cpy[101][101];
    scanf("%d", &N);
    for (int i = 0; i < N; i++){
        for (int j = 0;j < N; j++){
            scanf("%d", &Root[i][j]);
            cpy[i][j] = Root[i][j];
        }
    }
    for (int i=0;i<N;i++){
        for (int j=0;j<N;j++){
            if (Root[i][j]){
                dfs(i,j,Root,cpy);
            }
        }
    }
    for (int i=0;i<N;i++){
        for (int j=0;j<N;j++)
            printf("%d ",cpy[i][j]);
        printf("\n");
    }
    return 0;
}