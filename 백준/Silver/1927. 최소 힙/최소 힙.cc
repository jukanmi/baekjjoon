#include <iostream>
#include <queue>
using namespace std;
int main() {
	int N, x;
	priority_queue<int>num;
	scanf("%d", &N);
	while (N--) {
		scanf("%d", &x);
		if (x == 0) {
			if (num.empty()) {
				printf("0\n");
				continue;
			}
			printf("%d\n", -num.top());
			num.pop();
			continue;
		}
		num.push(-x);
	}
}