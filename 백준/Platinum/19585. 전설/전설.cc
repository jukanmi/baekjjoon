#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define FIO ios_base::sync_with_stdio(0);cin.tie(0); cout.tie(0);
#define endl "\n"
#define input freopen("input.txt", "r", stdin);
class node {
public:
	bool ed = 0;
	map<char, node*> next;
	node() {}

	node* find(char fc) {
		auto it = next.find(fc);
		if (it != next.end()) return it->second;
		return NULL;
	}

	node* push(char nc) {
		node* n = new node();
		next[nc] = n;
		return n;
	}
};

int C, N;
node* color = new node();
node* name = new node();
bool Cidx[2003];
int main() {
	FIO;
	cin >> C >> N;
	string s;
	node* root = color;

	while (C--) {
		cin >> s;
		node* cur = root;
		for (char cc : s) {
			node* move = cur->find(cc);
			if (move == NULL)
				cur = cur->push(cc);
			else
				cur = move;
		}
		cur->ed = 1;
	}

	root = name;
	while (N--) {
		cin >> s;
		reverse(s.begin(), s.end());
		node* cur = root;
		for (char cc : s) {
			node* move = cur->find(cc);
			if (move == NULL)
				cur = cur->push(cc);
			else
				cur = move;
		}
		cur->ed = 1;
	}

	int Q;
	cin >> Q;
	while (Q--) {
		fill(Cidx,Cidx+2003, 0);
		cin >> s;
		bool ans = 0;
		node* cur = color;
		int len = s.length();
		for (int i=0;i<len;i++) {
			cur = cur->find(s[i]);
			if (cur == NULL)
				break;
			if (cur->ed)
				Cidx[len-2-i] = 1;
		}

		reverse(s.begin(),s.end());
		cur = name;
		for (int i = 0; i < len; i++) {
			cur = cur->find(s[i]);
			if (cur == NULL)
				break;
			if (cur->ed && Cidx[i]) {
				ans = 1;
				break;
			}
		}
		puts(ans ? "Yes" : "No");
	}
}