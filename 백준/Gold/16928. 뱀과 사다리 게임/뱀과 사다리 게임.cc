#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;
#define FIO ios_base::sync_with_stdio(0);cin.tie(0); cout.tie(0);
class plate {
public:
    int move = 0;
    int pannel = 0;
    plate(int p) {
        pannel = p;
        move = p;
    }
    void set(int s) {
        move = s;
    }
    int mv() {
        return move;
    }
};
int main() {
    FIO;
    int N, M, cnt = 0;
    vector<plate*> v(101);
    queue<pair<int, int>> Q;
    cin >> N >> M;
    for (int i = 1; i < 101; i++)
        v[i] = new plate(i);
    int x, y;
    for (int i = 0; i < N+M; i++) {//사다리+뱀
        cin >> x >> y;
        v[x]->set(y);
    }
    Q.push(make_pair(1, 0));
    while (Q.front().first + 6 < 100) {
        int curr = Q.front().first, cnt = Q.front().second;
        bool greedy = true;
        for (int i = 6; i > 0; i--) {
            int mv = v[curr + i]->move;
            if (mv == curr + i) {
                if (greedy) {
                    Q.push(make_pair(mv, cnt + 1));
                    greedy = false;
                }
            }
            else {
                Q.push(make_pair(mv, cnt + 1));
            }
        }
        Q.pop();
    }
    cout << Q.front().second + 1 << endl;
}