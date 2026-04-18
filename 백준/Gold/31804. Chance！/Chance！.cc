#include <iostream>
#include <queue>
#include <unordered_set>

using namespace std;

struct State {
    int value;
    int steps;
    bool used_chance;
};

int solve(int a, int b) {
    queue<State> q;
    q.push({a, 0, false});
    unordered_set<long long> visited;

    while (!q.empty()) {
        State cur = q.front(); q.pop();

        if (cur.value == b) return cur.steps;
        long long key = (long long)cur.value * 2 + cur.used_chance;
        if (visited.count(key)) continue;
        visited.insert(key);

        if (cur.value + 1 <= 1000000)
            q.push({cur.value + 1, cur.steps + 1, cur.used_chance});

        if (cur.value * 2 <= 1000000)
            q.push({cur.value * 2, cur.steps + 1, cur.used_chance});

        if (!cur.used_chance && cur.value * 10 <= 1000000)
            q.push({cur.value * 10, cur.steps + 1, true});
    }

    return -1;
}

int main() {
    int a, b;
    cin >> a >> b;
    cout << solve(a, b) << endl;
    return 0;
}
