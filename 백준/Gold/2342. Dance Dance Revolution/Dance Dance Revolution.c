#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#define MAX 2147483647
#define ll long long
int sbs(int x, int y);
int min(int a, int b){return (a < b) ? a : b;}
int dfs(int l, int r, int e);
int tmp,DDR[100002][5][5],command[100000],len;
int main() {
    do{
        scanf("%d",&command[len++]);
    }while (command[len-1]);
    len--;
    printf("%d",dfs(0,0,0));
    return 0;
}

int sbs(int x, int y){
    if (x==0) return 2;
    if (x==1){
        if (y==2||y==4) return 3;
        if (y==1) return 1;
        if (y==3) return 4;
    }
    if (x==2){
        if (y==1||y==3) return 3;
        if (y==2) return 1;
        if (y==4) return 4;
    }
    if (x==3){
        if (y==2||y==4) return 3;
        if (y==3) return 1;
        if (y==1) return 4;
    }
    if (x==4){
        if (y==1||y==3) return 3;
        if (y==4) return 1;
        if (y==2) return 4;
    }
}
int dfs(int l, int r, int e){
    if (e==len)return 0;
    if (DDR[e][l][r]) return DDR[e][l][r];
    return DDR[e][l][r]=min(sbs(l,command[e])+dfs(command[e],r,e+1),sbs(r,command[e])+dfs(l,command[e],e+1));
}