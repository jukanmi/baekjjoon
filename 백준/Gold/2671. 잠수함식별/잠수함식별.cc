#include <bits/stdc++.h>
using namespace std;
string str;
int t;
void automato(int c){
	switch(t) {		
        case 0:t=c?3:1;break;
		case 1:t=c?2:-1;break;
		case 2:t=c?3:1;break;
		case 3:t=c?-1:4;break;
		case 4:t=c?-1:5;break;
		case 5:t=c?6:5;break;
		case 6:t=c?7:1;break;
		case 7:t=c?7:8;break;
		case 8:t=c?2:5;break;
	}
}

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0); cout.tie(0);
	int N=1;
	for (int i=0;i<N;i++){
		cin >> str;
		t=0;

		for (char c:str)

			automato(c-'0');

		puts(t==6||t==7||t==2?"SUBMARINE":"NOISE");

	}

}