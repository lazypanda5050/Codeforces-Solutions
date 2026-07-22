/*
 * It is useless to perform an operation when a[i] or a[i+1] == 0
 * 0 0 0 0 0 0 0 4
 * if a[i] > a[i+1] then impossible
 * always start with i = 0
*/

#include <bits/stdc++.h>
using namespace std;

int main(){
  int T;
  cin >> T;
  while (T--){
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++){
      cin >> a[i];
    }

    bool broken = false;
    for (int i = 0; i < n-1; i++){
      if (a[i] > a[i+1]){
        cout << "NO\n";
        broken = true;
        break;
      }

      a[i+1] -= a[i];
      a[i] = 0; // a[i] has to be the smaller one
    }

    if (!broken){
      cout << "YES\n";
    }
  }
}
