#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#define endl "\n"
using namespace std;
typedef long long ll;
#define FIO\
	ios_base::sync_with_stdio(0);\
	cin.tie(0); cout.tie(0);
typedef struct node {
	node* left;
	node* right;
	char name;
}node;
int N;
vector<node> tree;
void fprint(node curr) {
	cout << curr.name;
	if (curr.left)
		fprint(*curr.left);
	if (curr.right)
		fprint(*curr.right);
}
void mprint(node curr) {
	if (curr.left)
		mprint(*curr.left);
	cout << curr.name;
	if (curr.right)
		mprint(*curr.right);
}
void eprint(node curr) {
	if (curr.left)
		eprint(*curr.left);
	if (curr.right)
		eprint(*curr.right);
	cout << curr.name;
}
int main() {
	FIO;
	int N;
	char p, l, r;
	cin >> N;
	tree = vector<node>(N + 1);
	for (int i = 0; i < N; i++) {
		cin >> p >> l >> r;
		tree[p - 'A'].name = p;
		if (l != '.') tree[p - 'A'].left = &tree[l - 'A'];
		if (r != '.') tree[p - 'A'].right = &tree[r - 'A'];
	}
	fprint(tree[0]);
	cout << endl;
	mprint(tree[0]);
	cout << endl;
	eprint(tree[0]);
	cout << endl;
}