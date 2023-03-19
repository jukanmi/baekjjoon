#include <bits/stdc++.h>
using namespace std;
#define FIO ios_base::sync_with_stdio(0);cin.tie(0); cout.tie(0);
int N;
class node {
public:
    string s;
    vector<node*> next;
    node(string ss) { s = ss; }
    node* find(string ss) {
        for (node* n : next)
            if (n->s == ss)
                return n;
        return NULL;
    }
    node* push(string ss) {
        node* n = new node(ss);
        next.push_back(n);
        return n;
    }
};
bool cmp(node* a, node* b) {
    return a->s < b->s;
}
void dfs(node* cur,int floor) {
    if (cur->s != "") {
        for (int i = 0; i < floor; i++)cout << "--";
        cout << cur->s << "\n";
    }
    sort(cur->next.begin(), cur->next.end(), cmp);
    for (node* n : cur->next)
        dfs(n, floor + 1);
}
int main() {
    FIO;
    cin >> N;
    node* root = new node("");
    vector<node*> nodes(1, root);
    while (N--){
        int M;
        cin >> M;
        node* curr = root;
        while (M--) {
            string s;
            cin >> s;
            node* f = curr->find(s);
            if (f != NULL)
                curr = f;
            else {
                curr = curr->push(s);
                nodes.push_back(curr);
            }
        }
    }
    dfs(root, -1);
}