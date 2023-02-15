#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
#define FIO ios_base::sync_with_stdio(0);cin.tie(0); cout.tie(0);
typedef long long ll;
char field[12][6];
void drop();
bool find4();
bool inrange(int x, int y) { return 0 <= x && x < 12 && 0 <= y && y < 6; }
void dfs(int x, int y,bool visit[12][6], vector<pair<int, int>>& bomb) {
    visit[x][y] = 1;
    bomb.push_back(make_pair(x, y));
    if (inrange(x - 1, y) && !visit[x - 1][y] && field[x][y] == field[x - 1][y]) dfs(x - 1, y, visit, bomb);
    if (inrange(x + 1, y) && !visit[x + 1][y] && field[x][y] == field[x + 1][y]) dfs(x + 1, y, visit, bomb);
    if (inrange(x, y - 1) && !visit[x][y - 1] && field[x][y] == field[x][y - 1]) dfs(x, y - 1, visit, bomb);
    if (inrange(x, y + 1) && !visit[x][y + 1] && field[x][y] == field[x][y + 1]) dfs(x, y + 1, visit, bomb);
}
int main() {
    FIO;
    for (int i = 0; i < 12 * 6; i++) field[i / 6][i % 6] = '.';
    for (int i = 0; i < 12; i++)
        for (int j = 0; j < 6; j++)
            cin >> field[i][j];
    int ans = 0;
    while (find4()) {
        drop();
        ans++;
        /*
        cout << endl;
        for (int i = 0; i < 12; i++) {
            for (int j = 0; j < 6; j++)
                cout << field[i][j];
            cout << endl;
        }
        /**/
    }
    cout << ans << endl;
}
void drop() {
    for (int i = 0; i < 6; i++) {
        int idx = 11;
        for (int j = 11; j >= 0; j--) {
            if (field[j][i] != '.' && j != idx)
                field[idx--][i] = field[j][i], field[j][i] = '.';
            else if (field[idx][i] != '.')
                idx--;
        }
    }
}
bool find4() {
    bool visit[12][6] = { 0 }, flag = false;
    for (int i = 0; i < 12; i++)
        for (int j = 0; j < 6; j++)
            if (field[i][j] != '.' && visit[i][j] == false) {
                vector<pair<int, int>> bomb;
                dfs(i, j, visit, bomb);
                if (!flag) flag = (bomb.size() >= 4);
                if (bomb.size()>=4)
                    for (pair<int, int> idx : bomb)
                        field[idx.first][idx.second] = '.';
            }
    return flag;
}