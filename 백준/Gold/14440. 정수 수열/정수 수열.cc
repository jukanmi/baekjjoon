#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int MOD = 100;
void init() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cout.precision(2);
  cout << fixed;
}
void poo(int arr[][2]) {
	int a[2][2];
	for (int i = 0; i < 4; i++)
		a[i / 2][i % 2] = arr[i / 2][i % 2];
	for (int i = 0; i < 4; i++)
		arr[i / 2][i % 2] = 0;
	for (int i = 0; i < 2; i++)
		for (int j = 0; j < 2; j++)
			for (int z = 0; z < 2; z++) {
				arr[i][j] += (a[i][z] * a[z][j])%MOD;
				arr[i][j] %= MOD;
			}
}
void poo(int arr[][2], int a[]) {
	int tmp = a[0];
	a[0] = (a[0] * arr[0][0])%MOD + (a[1] * arr[0][1])%MOD;
	a[1] = (tmp * arr[1][0])%MOD + (a[1] * arr[1][1])%MOD;
	a[0] %= MOD;
	a[1] %= MOD;
}
int fivo(int n, int x,int y, int a0, int a1) {
	if (n == -1) return 0;
	int arr[][2] = { {0,1},{y,x} };
	int a[] = { a0,a1 };
	while (n>0) {
		if (n & 1)
			poo(arr, a);
		poo(arr);
		n >>= 1;
	}
	return a[0] % MOD;
}
int main() {
  init();
  int x,y,a0,a1,n;
  cin >> x>>y>>a0>>a1>>n;
  printf("%02d", fivo(n, x, y, a0, a1)%MOD) << '\n';
}
