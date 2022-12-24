#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <tuple>
#define endl "\n"
using namespace std;
typedef long long ll;
#define FIO\
	ios_base::sync_with_stdio(0);\
	cin.tie(0); cout.tie(0);
typedef struct reserve {
	int year;
	int month;
	int day;
	int hour;
	int min;
}reserve;
typedef struct a {
	string idx;
	reserve start;
	reserve end;
}a;
bool isyun(int year);
int date(int month, int year);
void add_min(reserve* end, int min);
bool cmp(a f, a s);
bool compare(reserve f, reserve e);
vector<a> list;
vector<reserve> used;
int main() {
	FIO;
	//freopen("input.txt", "r", stdin);
	int T;
	cin >> T;
	while (T--) {
		int Max = 0;
		int B, C;
		cin >> B >> C;
		for (int i = 0; i < B; i++) {
			char tmp;
			a b;
			cin >> b.idx >> b.start.year >> tmp >> b.start.month >> tmp >> b.start.day >> b.start.hour >> tmp >> b.start.min >> b.end.year >> tmp >> b.end.month >> tmp >> b.end.day >> b.end.hour >> tmp >> b.end.min;

			add_min(&(b.end), C);

			list.push_back(b);
		}
		sort(list.begin(), list.end(), cmp);
		for (a res : list) {
			for (int i = 0; i < used.size(); i++) {
				if (compare(used[i], res.start)) {//종료시간<=시작시간
					used.erase(used.begin() + i);
					i--;
				}
			}
			used.push_back(res.end);
			Max = Max < used.size() ? used.size() : Max;
		}
		cout << Max << endl;
		list.clear();
		used.clear();
	}
}
bool isyun(int year) {
	if (year % 4 == 0 && year % 100 != 0) return true;
	else {
		if (year % 400 == 0) return true;
		else return false;
	}
}
int date(int month, int year) {
	int dates[12] = { 31,28,31,30,31,30,31,31,30,31,30,31 };
	if (month!=2)
		return dates[month - 1];
	if (isyun(year))
		return 29;
	else
		return 28;
}
void add_min(reserve* end, int min) {
	(*end).min += min;
	if ((*end).min >= 60) {
		(*end).hour += (*end).min / 60;
		(*end).min %= 60;
		if ((*end).hour >= 24) {
			(*end).hour %= 24;
			(*end).day++;
			if ((*end).day > date((*end).month, (*end).year)) {
				(*end).day = ((*end).day - 1) % date((*end).month, (*end).year) + 1;
				(*end).month++;
				if ((*end).month > 12) {
					(*end).month = ((*end).month - 1) % 12 + 1;
					(*end).year++;
				}
			}
		}
	}
}
bool cmp(a f, a s) {
	if (f.start.year < s.start.year) return true;
	else if (f.start.year > s.start.year) return false;

	if (f.start.month < s.start.month) return true;
	else if (f.start.month > s.start.month) return false;

	if (f.start.day < s.start.day) return true;
	else if (f.start.day > s.start.day) return false;

	if (f.start.hour < s.start.hour) return true;
	else if (f.start.hour > s.start.hour) return false;

	if (f.start.min < s.start.min) return true;
	else if (f.start.min > s.start.min) return false;

	return false;
}
bool compare(reserve f, reserve s) {
	if (f.year < s.year) return true;
	else if (f.year > s.year) return false;

	if (f.month < s.month) return true;
	else if (f.month > s.month) return false;

	if (f.day < s.day) return true;
	else if (f.day > s.day) return false;

	if (f.hour < s.hour) return true;
	else if (f.hour > s.hour) return false;

	if (f.min < s.min) return true;
	else if (f.min > s.min) return false;

	return true;
}