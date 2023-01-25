#include <iostream>
#include <vector>
#define FIO\
	ios_base::sync_with_stdio(0);\
	cin.tie(0); cout.tie(0);
using namespace std;
#define endl "\n"
vector<int> num;
int root(int Start, int *count) {
    (*count)++;
    if (num[Start] == -1) return Start;
    return num[Start] = root(num[Start],count);
}

int main() {
    FIO;
    //freopen("input.txt", "r", stdin);
    int N, M;
    cin >> N >> M;
    num.resize(N + 1,-1);
    for (int i = 0; i < M; i++) {//100,000
        int a, b, c;
        cin >> a >> b >> c;
        if (a) {
            if (root(b,&a)==root(c,&a)) cout << "YES\n";
            else cout << "NO\n";
        }
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