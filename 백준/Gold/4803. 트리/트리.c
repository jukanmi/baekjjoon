#include <stdio.h>
#include <string.h>
#include <stdbool.h>
int arr[501];
int N, M, Case;
bool root(int x, int count) {
    if (!arr[x]) return true;
    if (count>500) return false;
    int ro = arr[x];
    root(arr[x], count+1);
    arr[ro] = x;
}
int main() {
    //freopen("input.txt", "r", stdin);
    while (++Case) {
        //입력
        scanf("%d%d", &N, &M);
        if (!N && !M) break;
        for (int i = 0; i < M; i++) {
            int a, b;
            scanf("%d%d", &a, &b);
            if (!arr[a])
                arr[a] = b;
            else if (!arr[b])
                arr[b] = a;
            else {
                if (root(a, 0))
                    arr[a] = b;
            }
        }

        //계산
        int ans = 0;
        for (int i = 1; i <= N; i++)
            if (!arr[i])
                ans++;

        //출력
        printf("Case %d: ", Case);
        if (!ans) puts("No trees.");
        else if (ans == 1) puts("There is one tree.");
        else printf("A forest of %d trees.\n", ans);
        memset(arr, 0, (N + 1) * 4);
    }
}