#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

struct Assignment {
    int deadline;
    int score;
};

bool compare(const Assignment& a, const Assignment& b) {
    return a.score > b.score;
}

int main() {
    int N;
    cin >> N;

    vector<Assignment> assignments(N);
    for (int i = 0; i < N; i++) {
        cin >> assignments[i].deadline >> assignments[i].score;
    }

    sort(assignments.begin(), assignments.end(), compare);

    vector<bool> days(N + 1, false);
    int totalScore = 0;
    for (int i = 0; i < N; i++) {
        for (int j = assignments[i].deadline; j > 0; j--) {
            if (!days[j]) {
                days[j] = true;
                totalScore += assignments[i].score;
                break;
            }
        }
    }

    cout << totalScore << endl;

    return 0;
}
