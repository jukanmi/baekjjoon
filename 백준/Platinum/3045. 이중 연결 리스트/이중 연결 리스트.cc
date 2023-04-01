#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define FIO ios_base::sync_with_stdio(0);cin.tie(0); cout.tie(0);
#define endl "\n"
#define input freopen("input.txt", "r", stdin);
//#define DEBUG

class node {
public:
	int idx;
	node* next=NULL;
	node* prev=NULL;
	node(node* p, int i, node* n) {
		idx = i, next = n, prev = p;
	}
	node(int i) {
		idx = i;
	}
	node(int i, node* n) {
		idx = i, next = n;
	}
	node(node* p,int i) {
		idx = i, prev = p;
	}
};
class dblinkedList {
public:
	node *header,*trailer;
	vector<node*> nodes;
	dblinkedList(int N) {
		nodes.resize(N+1);
		header = new node(0);
		trailer = new node(header, N+1);
		header->next=trailer;
		nodes[0]=header;
	}
	void push_back(int idx) {
		node* add = new node(trailer->prev, idx,trailer);
		trailer->prev->next=add;
		trailer->prev=add;
		nodes[idx]=add;
	}
	void move(int idx, int nexto) {
		if (idx >= nodes.size() || nexto >= nodes.size()||idx==nexto) return;
		//연결해제
		nodes[idx]->prev->next = nodes[idx]->next;
		nodes[idx]->next->prev = nodes[idx]->prev;
		//부착
		nodes[idx]->next = nodes[nexto]->next;
		nodes[idx]->prev = nodes[nexto];
		nodes[nexto]->next->prev = nodes[idx];
		nodes[nexto]->next = nodes[idx];
	}
};
int N, M;
/**
* S에서 가장 긴 증가하는 부분 수열을 찾아 리턴하는 함수
* @param S 수열
* @param N S의 길이
* #return S에서 가장 긴 증가하는 부분 수열(vector)
*/
vector<int> growing(vector<int>& S, int N) {
	vector<int> locate(N), A(N);
	int len = 1;
	A[0] = S[0];
	locate[0] = 0;
	for (int i = 1; i < N; i++) {
		if (A[len - 1] < S[i]) {
			locate[i] = len;
			A[len++] = S[i];
			continue;
		}
		int l = 0, r = len - 1;
		while (l < r) {
			int m = (l + r) / 2;
			if (A[m] < S[i])l = m + 1;
			else r = m;
		}
		A[l] = S[i];
		locate[i] = l;
	}
	vector<int> ans(len);
	len--;
	for (int i = N - 1; i >= 0 && len >= 0; i--)
		if (locate[i] == len)
			ans[len--] = S[i];
	return ans;
}
int main() {
	FIO;
	//input;
	cin >> N >> M;
	dblinkedList list= dblinkedList(N);
	for (int i = 1; i <= N; i++)
		list.push_back(i);
	while (M--) {
		char a;
		int b, c;
		cin >> a >> b >> c;
		if (a == 'A')
			c=list.nodes[c]->prev->idx;
		list.move(b, c);
	}
	vector<int> arr(N);
	node* cur = list.header;
	cur = cur->next;
	for (int i = 0; cur != list.trailer;i++) {
		arr[i] = cur->idx;
		cur = cur->next;
	}
	vector<int> ans = growing(arr, N);
	int idx=0,size=ans.size();
	cout << N - size << endl;
	for (int i = 1; i <= N; i++) {
		if (idx < size && ans[idx] == i) {
			idx++;
			continue;
		}
		if (!idx) {
#ifdef DEBUG
			list.move(i, list.nodes[ans[0]]->prev->idx);
#endif // DEBUG
			cout << "A " << i << " " << ans[0] << endl;
		}
		else {
#ifdef DEBUG
			list.move(i, i - 1);
#endif // DEBUG
			cout << "B " << i << " " << i - 1 << endl;
		}
	}
	//스페셜 저지
#ifdef DEBUG
	cur = list.header;
	cur = cur->next;
	for (int i = 0; cur != list.trailer; i++) {
		if (cur->idx != i + 1)
			puts("FAIL");
		cur = cur->next;
	}
#endif // DEBUG
	return 0;
}