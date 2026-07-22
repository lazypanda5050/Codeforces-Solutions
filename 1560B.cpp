#include <bits/stdc++.h>
using namespace std;

int main(){
  int T;
  cin >> T;
  while (T--){
    int a,b,c;
    cin >> a >> b >> c;
    
    int n = 2*abs(a-b);
    if (a > n || b > n || c > n){
      cout << -1 << '\n';
    }
    else{
      int d = n/2+c;
      while (d > n){
        d -= n;
      }
      cout << d << '\n';
    }
  }
}
