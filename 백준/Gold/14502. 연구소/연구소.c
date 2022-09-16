#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//연구소
int in[8][8],N,M,blank[64][2],blen,virus[64][2],vlen,copy[8][8];
void wasd(int x,int y) {
    copy[x][y] = -1;
    if ((x < N - 1) && (copy[x + 1][y] == 0))
        wasd(x + 1, y);
    if ((y < M - 1) && (copy[x][y + 1] == 0))
        wasd(x, y + 1);
    if ((x > 0) && (copy[x - 1][y] == 0))
        wasd(x - 1, y);
    if ((y > 0) && (copy[x][y - 1] == 0))
        wasd(x, y - 1);
}

int search(int* w) {
    int safe = 0;
    for (int i = 0; i < N; i++)
        for (int j = 0; j < M; j++)
            copy[i][j] = in[i][j];
    //초기화
    for (int i = 0; i < 6; i += 2)
        copy[w[i]][w[i + 1]] = 1;
    //벽세우기
    for (int i = 0; i < vlen; i++)   
        wasd(virus[i][0], virus[i][1]);
    //바이러스마다 감염하기
    for (int i = 0; i < N; i++)
        for (int j = 0; j < M; j++)
            if (!copy[i][j])
                safe++;
    //안전구역 확인
    return safe;
}
int main() {
    int max = 0;
    scanf("%d %d", &N, &M);
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            scanf("%d", &in[i][j]);
            if (in[i][j] == 0) {
                blank[blen][0] = i;
                blank[blen++][1] = j;
            }
            else if (in[i][j] == 2) {
                virus[vlen][0] = i;
                virus[vlen++][1] = j;
            }
        }
    }
    int point[6];
    for (int a = 0; a < blen-2; a++) {
        point[0] = blank[a][0];
        point[1] = blank[a][1];
        for (int b = a + 1; b < blen-1; b++) {
            point[2] = blank[b][0];
            point[3] = blank[b][1];
            for (int c = b + 1; c < blen; c++) {
                point[4] = blank[c][0];
                point[5] = blank[c][1];
                int retu=search(point);
                if (retu > max)
                    max = retu;
            }
        }
    }
    printf("%d", max);
    return 0;
}