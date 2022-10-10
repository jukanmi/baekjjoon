#include <iostream>
#include <queue>
#include <vector>
#include <map>
#include <string>
#define base\
	ios_base::sync_with_stdio(0);\
	cin.tie(0); cout.tie(0);
using namespace std;
//이중우선순위큐
int main() {
	base;
	int N,M;
	cin >> N >> M;
	map <string,string> pass;
	string site,password;
	for (int i=0;i<N;i++) {
		cin >> site >> password;
		pass[site] = password;
	}
	for (int  i=0;i<M;i++) {
		cin >> site;
		cout << pass[site] << '\n';
	}
}