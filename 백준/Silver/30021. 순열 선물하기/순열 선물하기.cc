#include <iostream>
#include <vector>

using namespace std;
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int n;
  cin >> n;
  if (n==1){
    cout << "YES\n1" << endl;
    return 0;
  }
  if (n<3){
    cout << "NO" << endl;
    return 0;
  }
  if (n==3){
    cout << "YES\n1 3 2" << endl;
    return 0;
  }
    vector<int> arr = {4,2,3};
    for (int i=5; i <= n; i++) {
    arr.push_back(i);
    if (i%2==0)
      swap(arr[i-2], arr[i-3]);
  }
  arr.push_back(1);
  cout << "YES\n";
  for (int i=0; i<arr.size(); i++)
    cout << arr[i] << " ";
}
