#include <iostream>
#include <cmath>
using namespace std;
#define FIO ios_base::sync_with_stdio(0);cin.tie(0); cout.tie(0);
int LCS[101][101][101];
int maximum(int a, int b, int c){return max(max(a,b),c);}
int main(){
	FIO;
	string a,b,c;
	cin >> a >> b >> c;
	for (long unsigned int i=1;i<=a.length();i++){
		for (long unsigned int j=1;j<=b.length();j++){
			for (long unsigned int k=1;k<=c.length();k++){
				if (a[i-1]==b[j-1]&&b[j-1]==c[k-1])
					LCS[i][j][k] = LCS[i-1][j-1][k-1]+1;
				else
					LCS[i][j][k] = maximum(LCS[i-1][j][k],LCS[i][j-1][k],LCS[i][j][k-1]);
			}
		}
	}
	cout << LCS[a.length()][b.length()][c.length()] << endl;
}