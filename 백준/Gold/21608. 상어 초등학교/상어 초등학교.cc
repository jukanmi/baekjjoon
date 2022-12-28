#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <cctype>
#define endl "\n"
using namespace std;
typedef long long ll;
#define FIO\
	ios_base::sync_with_stdio(0);\
	cin.tie(0); cout.tie(0);
int N;
int relate[401][5];
int seat[21][21];
int swi[401] = { -1 };
//가중치(빈칸, 친구)
int* blank(int x, int y);
int* greedy(int num);
int calcul();
int main() {
	FIO;
	//freopen("input.txt", "r", stdin);
	cin >> N;
	for (int i = 0; i < N * N; i++)
		cin >> relate[i][0] >> relate[i][1] >> relate[i][2] >> relate[i][3] >> relate[i][4];
	for (int i = 0; i < N * N; i++) {
		int* locate = greedy(i);
		seat[locate[0]][locate[1]] = relate[i][0];
	}
	cout << calcul();
	return 0;
}
int res[2];
int* blank(int x, int y) {
	res[0] = 0, res[1] = 0;
	if (y > 0) {
		res[0] += !seat[x][y - 1];
		res[1] += seat[x][y - 1] && seat[x][y - 1] == swi[seat[x][y - 1]];
	}
	if (x > 0) {
		res[0] += !seat[x - 1][y];
		res[1] += seat[x - 1][y] && seat[x - 1][y] == swi[seat[x - 1][y]];
	}
	if (x < N - 1) {
		res[0] += !seat[x + 1][y];
		res[1] += seat[x + 1][y] && seat[x + 1][y] == swi[seat[x + 1][y]];
	}
	if (y < N - 1) {
		res[0] += !seat[x][y + 1];
		res[1] += seat[x][y + 1] && seat[x][y + 1] == swi[seat[x][y + 1]];
	}
	return res;
}
int location[2];
int* greedy(int num) {
	for (int i = 1; i <= N * N; i++) swi[i] = 0;
	for (int i = 1; i < 5; i++)
		swi[relate[num][i]] = relate[num][i];
	location[0] = 0; location[1] = 0;
	int mx[2] = { -1,-1 };
	int* tmp;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (!seat[i][j]) {
				tmp = blank(i, j);
				if (mx[1] < tmp[1] || (mx[1] == tmp[1] && mx[0] < tmp[0])) {
					mx[0] = tmp[0], mx[1] = tmp[1]; location[0] = i, location[1] = j;
				}
			}
		}
	}
	return location;
}
int calcul() {
	int ans = 0;
	for (int j = 0; j < N * N; j++) {
		int x, y=0, flag = 1;
		for (x = 0; x < N && flag; x++) {
			for (y = 0; y < N && flag; y++) {
				if (seat[x][y] == relate[j][0]) {
					flag = 0;
					break;
				}
			}
		}
		x--;
		for (int i = 1; i <= N * N; i++) swi[i] = 0;
		for (int i = 1; i < 5; i++) swi[relate[j][i]] = relate[j][i];
		int* ptr = blank(x, y);
		if (ptr[1] == 4)
			ans += 1000;
		else if (ptr[1] == 3)
			ans += 100;
		else if (ptr[1] == 2)
			ans += 10;
		else if (ptr[1] == 1)
			ans++;
	}
	return ans;
}