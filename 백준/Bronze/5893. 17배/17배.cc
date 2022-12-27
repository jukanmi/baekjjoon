#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;
#define endl "\n"
#define FIO ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
typedef long long ll;
#define SWAP(x,y) {int tmp=(x);(x)=(y);(y)=tmp;}


int main() {
	FIO;
	char N[1050],Sum[1050];
	cin >> N;
	int len=strlen(N);
	if (len==1&&N[0]=='0'){
		cout << 0<< endl;
		return 0;
	}
	for (int i=0;i<len/2;i++){
		SWAP(N[i],N[len-i-1]);
	}
	for (int i=0;i<len;i++)
		Sum[i]=N[i];
	for (int i=len;i<1050;i++)
		Sum[i]='0';
	for (int i=0;i<len;i++){
		if (N[i]=='1'){
			int idx=i+4;
			while (Sum[idx]=='1'){
				Sum[idx++]='0';
			}
			Sum[idx]='1';
		}
	}
	int end=1049;
	while (Sum[end]=='0')
		end--;
	while (end>=0)
		cout << Sum[end--];
	
}