#include <bits/stdc++.h>
using namespace std;

int main(){
  int T;
  cin >> T;
  while (T--){
    int n;
    cin >> n;
    vector<int> a(n);
    vector<int> rightmost(n+1, 0); // the index of the rightmost maximum for the first i elements
    for (int i = 0; i < n; i++){
      cin >> a[i];
      if (a[i] >= a[rightmost[i]]){
        rightmost[i+1] = i;
      }
      else{
        rightmost[i+1] = rightmost[i];
      }
    }

    int cur = n; // number of elements left
    int ans = 0;
    while (cur > 0){
      ans++;
      cur = rightmost[cur];
    }

    cout << ans << '\n';
  }
}
