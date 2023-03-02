#include <bits/stdc++.h>
using namespace std;
string str;
void automato(int *Case, int c){
	switch(*Case) {
		case 0:*Case=c?3:1;break;
		case 1:*Case=c?2:-1;break;
		case 2:*Case=c?3:1;break;
		case 3:*Case=c?-1:4;break;
		case 4:*Case=c?-1:5;break;
		case 5:*Case=c?6:5;break;
		case 6:*Case=c?7:1;break;
		case 7:*Case=c?7:8;break;
		case 8:*Case=c?2:5;break;
	}
}
int main(){
    ios_base::sync_with_stdio(0);cin.tie(0); cout.tie(0);
	int N;
	cin >> N;
	for (int i=0;i<N;i++){
		cin >> str;
		int Case=0;
		for (char c:str)
			automato(&Case,c-'0');
		puts(Case==6||Case==7||Case==2?"YES":"NO");
	}
}