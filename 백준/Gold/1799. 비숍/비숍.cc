#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
#define FIO ios_base::sync_with_stdio(0);cin.tie(0); cout.tie(0);
int N, tmp;
vector<vector<pair<int, int>>> A;
vector<bool> col;
int ansA,ansB;
void func(int line, int w) {
    ansA = ansA < w ? w : ansA;
    if (line > 2 * N - 1)
        return;
    for (int r = 0; r < A[line].size(); r++) {
        if (col[A[line][r].second + N - A[line][r].first]) {
            col[A[line][r].second + N - A[line][r].first] = false;
            func(line + 2, w + 1);
            col[A[line][r].second + N - A[line][r].first] = true;
        }
    }
    func(line + 2, w);
}
int main() {
    FIO;
    cin >> N;
    A.resize(2 * N);
    col.resize(2 * N, true);
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++) {
            cin >> tmp;
            if (tmp)
                A[i + j].push_back(make_pair(i, j));
        }
    func(0, 0);
    ansB = ansA;
    ansA = 0;
    func(1, 0);
    cout << ansA+ansB << endl;
}