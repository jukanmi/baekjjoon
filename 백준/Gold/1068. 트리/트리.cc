#include <iostream>
#include <vector>
#include <algorithm>
#define MOD 1000000007
using namespace std;
typedef long long ll;
#define endl "\n"
#define FIO\
	ios_base::sync_with_stdio(0);\
	cin.tie(0); cout.tie(0);
class Node {
public:
	int index=0;
	Node* next[50] = { NULL ,};
	int nodelength = 0;
	Node(){}
	Node(int i) {
		index = i;
	}
	void add_Node(Node* node) {
		next[nodelength++] = node;
	}
	void remove_Node(int index) {
		int x = 0;
		for (int i = 0; i < nodelength; i++) {
			if (next[i]->index == index)
				next[i] = next[i + 1], x = 1;
			else {
				next[i] = next[i - x];
				next[i]->remove_Node(index);
			}

		}
		nodelength -= x;
	}
	int check_Node() {
		int len = 0;
		for (int i = 0; i < nodelength; i++) {
			if (next[i]->nodelength == 0)
				len++;
			else
				len += next[i]->check_Node();
		}
		return len;
	}
};

int main() {
	FIO
	int N, tmp;
	cin >> N;
	Node root;
	Node NODE[50];
	for (int i = 0; i < N; i++)
		NODE[i] = Node(i);
	for (int i = 0; i < N; i++) {
		cin >> tmp;
		if (tmp != -1)
			NODE[tmp].add_Node(&NODE[i]);
		else
			root.add_Node(&NODE[i]);
	}
	cin >> tmp;
	root.remove_Node(tmp);
	int ans = 0;
	ans += root.check_Node();
	cout << ans;
	return 0;
}