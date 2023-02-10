#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;
#define FIO ios_base::sync_with_stdio(0);cin.tie(0); cout.tie(0);
class fireball {
public:
    int x, y, m, d, s;
    bool mixed = false;
    fireball(int lx, int ly, int mass, int direct, int speed) {
        x = lx; y = ly; m = mass; d = direct; s = speed;
    }
    void move(int N) {
        switch (d) {
        case 0:x -= s; break;
        case 1:x -= s, y += s; break;
        case 2:y += s; break;
        case 3:x += s, y += s; break;
        case 4:x += s; break;
        case 5:x += s, y -= s; break;
        case 6:y -= s; break;
        case 7:x -= s, y -= s; break;
        default:break;
        }
        while (x < 0)
            x += N;
        x %= N;
        while (y < 0)
            y += N;
        y %= N;
    }
    bool equal(fireball* ball) { return ball->x == x && ball->y == y; }
};
void mix(vector<fireball*>& balls, vector<int>& crafting) {
    int mass = 0, direction = balls[crafting[0]]->d % 2, speed = 0;
    for (int b : crafting) {
        mass += balls[b]->m, speed += balls[b]->s;
        if (direction != -1 && direction != balls[b]->d % 2)
            direction = -1;
    }
    mass /= 5, speed /= crafting.size();
    if (direction != -1)direction = 0;
    else direction = 1;
    if (mass)
        for (int i = 0; i < 4; i++)
            balls.push_back(new fireball(balls[crafting[0]]->x, balls[crafting[0]]->y, mass, 2*i + direction, speed));
}
int main() {
    FIO;
    int N, M, K;
    cin >> N >> M >> K;
    vector<fireball*> balls(M);
    //입력
    for (int i = 0; i < M; i++) {
        int x, y, m, d, s;
        cin >> x >> y >> m >> s >> d;
        balls[i] = new fireball(x, y, m, d, s);
    }
    while (K--) {
        //이동
        for (fireball* ball : balls)
            ball->move(N);
        vector<int> crafting;//합체 지울거
        priority_queue<int> rm;
        for (int i = 0; i < M; i++) {//순환
            if (balls[i]->mixed == false) {//중복제거
                crafting.push_back(i);
                for (int j = i + 1; j < M; j++)
                    if (balls[i]->equal(balls[j])) {
                        crafting.push_back(j);
                        balls[j]->mixed = true;
                    }
                if (crafting.size() >= 2) {
                    mix(balls, crafting);
                    for (int a : crafting)
                        rm.push(a);
                }
                crafting.clear();
            }
        }
        //지우기
        while (!rm.empty()) {
            balls.erase(balls.begin() + rm.top());
            rm.pop();
        }
        M = balls.size();
    }
    int ans = 0;
    for (fireball* i : balls)
        ans += i->m;
    cout << ans << endl;
}