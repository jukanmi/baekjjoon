#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
typedef long long ll;
#define FIO\
	ios_base::sync_with_stdio(0);\
	cin.tie(0); cout.tie(0);
int main() {
	FIO;
	//freopen("input.txt", "r", stdin);
	string word,reverseword;
	vector<string> words;
	int n;
	cin >> n;
	for (int i=0;i<n;i++){
		cin >> word;
		reverseword = word;
		for (string w : words)
			if (w==word){
				cout << word.length() <<" " << word[word.length()/2] << endl;
				return 0;
			}
		reverse(reverseword.begin(), reverseword.end());
		if (reverseword==word){
			cout << word.length() <<" " << word[word.length()/2] << endl;
			return 0;
		}
		words.push_back(reverseword);
	}
}
