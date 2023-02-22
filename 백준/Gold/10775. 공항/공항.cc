#include <bits/stdc++.h>
using namespace std;
#define FIO ios_base::sync_with_stdio(0);cin.tie(0); cout.tie(0);
int root(int i, vector<int>& gate) {
    if (gate[i] == i)return i;
    return gate[i]=root(gate[i], gate);
}
void merge(int s, int i, vector<int>& gate) {
    int e=root(i,gate);
    gate[s] = e;
}
int main() {
    FIO;
    int G, P, tmp, ans = 0;
    cin >> G >> P;
    vector<int> gate(G + 1);
    for (int i = 1; i <= G; i++)
        gate[i] = i;
    for (int i = 0; i < P; i++) {
        cin >> tmp;
        int Root = root(tmp, gate);
        if (Root) {
            merge(Root, Root - 1, gate);
            ans++;
        }
        else
            break;
    }
    cout << ans << endl;
}