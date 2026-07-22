#include <bits/stdc++.h>
using namespace std;

int main(){
  int T;
  cin >> T;
  while (T--){
    int k;
    cin >> k;
    vector<int> c(k);
    int big = -1;
    int cnt = 0;
    for (int i = 0; i < k; i++){
      cin >> c[i];
      big = max(big, c[i]);
      cnt += (c[i] == 2);
    }

    if (big > 2 || cnt > 1){
      cout << "YES\n";
    }
    else{
      cout << "NO\n";
    }
  }
}
