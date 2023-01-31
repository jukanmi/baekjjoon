#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
#define FIO ios_base::sync_with_stdio(0);cin.tie(0); cout.tie(0);
vector<string> s;
int T, N;
class NODE {
public:
    char name='\0';
    NODE* head = NULL;
    NODE* tail = NULL;
    NODE* NEXT = NULL;
    NODE(char n) {
        name = n;
    };
    NODE() {
    };
    void addChild(NODE* child) {//새로운 노드를 추가
        if (head == NULL) {
            head = child;
            tail = child;
            return;
        }
        tail->NEXT = child;
        tail = child;
    }
    NODE* find(char c) {//문자 c를 가진 노드가 존재하는지 확인
        NODE* tmp = head;
        if (tmp == NULL) return NULL;
        while (tmp->NEXT != NULL && tmp->name != c) {
            tmp = tmp->NEXT;
        }
        if (tmp->name == c)return tmp;
        else return NULL;
    }
};
bool cmp(string s1, string s2) { return s1.length() < s2.length() || (s1.length() == s2.length() && s1 < s2); }
int main() {
    FIO;
    cin >> T;
    while (T--) {
        bool flag=true;
        NODE* root = new NODE();
        cin >> N;
        s.resize(N);
        for (int i = 0; i < N; i++)
            cin >> s[i];
        sort(s.begin(), s.end(), cmp);
        for (int i = 0; i < N&&flag; i++) {
            NODE* curr=root;
            bool NewWord = true;
            for (int j = 0; j < s[i].length(); j++) {
                if (curr->head == NULL&&!NewWord) {//일관성 없음
                    flag = false;
                    break;
                }
                NODE* ff = curr->find(s[i][j]);
                if (ff == NULL) {//노드를 찾지못함
                    curr->addChild(new NODE(s[i][j]));
                    curr = curr->tail;
                    NewWord = true;
                }
                else {//노드를 찾음
                    curr = ff;
                    NewWord = false;
                }
            }
        }
        if (flag) cout << "YES" << endl;
        else cout << "NO" << endl;
    }
    
}