#include <iostream>
using namespace std;
#define FIO\
	ios_base::sync_with_stdio(0);\
	cin.tie(0); cout.tie(0);

int main() {
	FIO;
	int A, B,a=0,b=0;
	cin >> A >> B;
	while (A != 1 && B != 1) {
		if (A > B) {
			a += A / B;
			A %= B;
		}
		else {
			b += B / A;
			B %= A;
		}
	}
	a += A - 1;
	b += B - 1;
	
	cout << a << " " << b;
}