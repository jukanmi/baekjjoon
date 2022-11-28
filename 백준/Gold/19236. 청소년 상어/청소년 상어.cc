#define yam num[map[sx][sy]]
#include <iostream>
using namespace std;
int mx[8] = { -1,-1,0,1,1,1,0,-1 };
int my[8] = { 0,-1,-1,-1,0,1,1,1 };
int ans;
bool check(int x, int y, int sx, int sy);
bool check(int x, int y);
class Fish {
public:
	int size=0, rotate=0, x=0, y=0;
	bool alive = true;
	/**
	* turn() - 이동 가능할때까지 회전함
	* @ param : sx - 상어 x좌표 sy - 상어 y좌표
	*/
	void turn(int sx, int sy) {
		while (!check(x + mx[rotate], y + my[rotate], sx, sy))
			rotate = ++rotate % 8;
	}
	Fish() {}
	Fish(int s, int r, int X, int Y) {
		size = s;
		rotate = r;
		x = X;
		y = Y;
	}
};
void func(int map[4][4], Fish num[17], int sx, int sy, int size, int rotate) {
	//yam - 상어가 위치한 곳의 물고기
	num[map[sx][sy]];
	if (!yam.alive) {
		ans = size > ans ? size : ans;
		return;//이미주겅
	}
	yam.alive = false;//주겅
	size += yam.size;//냠냠
	rotate = yam.rotate;//회전을 계승중입니다
	if (!check(sx + mx[rotate], sy + my[rotate])) {//한번도 못먹을 경우
		ans=ans<size?size:ans;
		return;
	}
	//물고기 움직임
	for (int i = 1; i <= 16; i++) {//번호순대로 반복
		num[7],num[6];
		if (!num[i].alive) continue;//죽었다면 탈출
		num[i].turn(sx,sy);
		//lo -옮기는 물고기가 도착한 위치의 물고기 번호
		int lo = map[num[i].x + mx[num[i].rotate]][num[i].y + my[num[i].rotate]];
		Fish tmp = num[i];//SWAP저장용11
		int temp = map[num[i].x][num[i].y];
		map[num[i].x][num[i].y], lo;
		map[num[i].x][num[i].y] = lo;
		map[num[lo].x][num[lo].y] = temp;
		num[i].x = num[lo].x, num[i].y = num[lo].y; // i번 회차에 선택된거 옮기기
		num[lo].x = tmp.x, num[lo].y = tmp.y;//SWAP
	}
	int cpmap[4][4];
	Fish cpnum[17];
	while (check(sx+mx[rotate], sy+my[rotate])) {
		for (int i = 0; i < 4; i++)
			for (int j = 0; j < 4; j++)
				cpmap[i][j] = map[i][j];
		for (int i = 1; i <= 16; i++)
			cpnum[i] = num[i];

		sx += mx[rotate], sy += my[rotate];
		func(cpmap, cpnum, sx,sy,size,rotate);
	}
	ans = size > ans ? size : ans;
	//printf("a %d\n", ans);
}
int main() {
	int map[4][4];
	Fish num[17];
	//freopen("Input.txt", "r", stdin);
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			int size, rotate;
			scanf("%d %d", &size,&rotate);
			map[i][j] = size;
			num[size].rotate = rotate-1;
			num[size].x = i;
			num[size].y = j;
			num[size].size = size;
		}
	}
	func(map, num, 0,0,0,0);
	printf("%d", ans);
}
bool check(int x, int y, int sx, int sy) {
	return 0 <= x && x <= 3 && 0 <= y && y <= 3 && (x != sx || y != sy);
}
bool check(int x, int y) { return 0 <= x && x <= 3 && 0 <= y && y <= 3 ; }
