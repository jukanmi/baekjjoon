int num[1000001];
int root(int S, int *c) {
    (*c)++;
    if (num[S] == -1) return S;
    return num[S] = root(num[S],c);
}
int main() {
    int N, M;
    scanf("%d%d", &N, &M);
    for (int i = 0; i <= N; i++) num[i] = -1;
    for (int i = 0; i < M; i++) {
        int a, b, c;
        scanf("%d%d%d", &a, &b, &c);
        if (a)
            puts(root(b, &a) - root(c, &a) ? "NO" : "YES");
        else {
            int cb = 0, cc = 0;
            int rb = root(b,&cb), rc = root(c, &cc);
            if (rb != rc) {
                if (cc > cb) num[rb] = rc;
                else num[rc] = rb;
            }
        }
    }
}