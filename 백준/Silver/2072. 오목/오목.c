#include <stdio.h>
int n,plate[20][20],x,y,num,try,ans,temp;
int check() {
	//가로
	for (int i = 1; i <= 19; i++) {
		for (int j = 1; j <= 19; j++) {
			if (plate[i][j]) {
				if (temp) {
					if (temp == plate[i][j]) num++;
					else num = 1;
				}
				else num++;
				temp = plate[i][j];
			}
			else {
				num = 0; temp = 0;
			}
			if (num == 5 && ((j == 19) || (j < 19 && plate[i][j + 1]!=temp))) { ans = try; return 1; }
		}
		num = 0; temp = 0;
	}
	//세로
	for (int i = 1; i <= 19; i++) {
		for (int j = 1; j <= 19; j++) {
			if (plate[j][i]) {
				if (temp) {
					if (temp == plate[j][i]) num++;
					else num = 1;
				}
				else num++;
				temp = plate[j][i];
			}
			else {
				num = 0; temp = 0;
			}
			if (num == 5 && ((j == 19) || (j < 19 && plate[j + 1][i]!=temp))) { ans = try; return 2; }
		}
		num = 0; temp = 0;
	}
	//우상향
	for (int z = 0; z < 2; z++) {
		for (int i = 1; i <= 19; i++) {
			if (z) {
				x = i;
				y = 1;
			}
			else {
				x = 19;
				y = i;
			}
			while (x <= 19 && x > 0 && y <= 19 && y > 0) {
				if (plate[x][y]) {
					if (temp) {
						if (temp == plate[x][y]) num++;
						else num = 1;
					}
					else num++;
					temp = plate[x][y];
				}
				else {
					num = 0; temp = 0;
				}
				if (num == 5) {
					if (x == 0 || y == 19) { ans = try; return 3; }
					if (plate[x - 1][y + 1] != temp) { ans = try; return 3; }
				}
				x--; y++;
			}
			num = 0; temp = 0; 
		}
	}
	//우하향
	for (int z = 0; z < 2; z++) {
		for (int i = 1; i <= 19; i++) {
			if (z) {
				x = i;
				y = 1;
			}
			else {
				x = 1;
				y = i;
			}
			while (x <= 19 && x > 0 && y <= 19 && y > 0) {
				if (plate[x][y]) {
					if (temp){
						if (temp == plate[x][y]) num++;
						else num = 1;
					}
					else num++;
					temp = plate[x][y];
				}
				else {
					num = 0; temp = 0;
				}
				if (num == 5) {
					if (x == 19 || y == 19) { ans = try; return 4; }
					if (plate[x + 1][y + 1] != temp) { ans = try; return 4; }
				}
				x++; y++;
			}
			num = 0; temp = 0; 
		}
	}
	return 0;
}
int main() {
	int n,m;
	scanf("%d", &n);
	while (n--) {
		scanf("%d%d", &x, &y);
		plate[x][y] = n % 2 ? 1 : -1;
		if (!ans) {
			try++;
			check();
		}
	}
	if (ans)printf("%d", ans);
	else printf("-1");
	return 0;
}
