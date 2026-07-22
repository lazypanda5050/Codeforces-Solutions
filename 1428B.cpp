#include <bits/stdc++.h>
using namespace std;

int solve(){
  int n;
  cin >> n;
  vector<bool> nxtTo(n, false); // if the ith node is next to a - belt

  int cw = 0;
  int ccw = 0;

  for (int i = 0; i < n; i++){
    char cur;
    cin >> cur;
    if (cur == '-'){
      nxtTo[i] = true;
      nxtTo[(i+1+n) % n] = true;
    }
    else if (cur == '>'){
      cw++;
    }
    else{
      ccw++;
    }
  }

  if (cw == 0 || ccw == 0){
    return n;
  }

  int ans = 0;
  for (int i = 0; i < n; i++){
    ans += nxtTo[i];
  }

  return ans;
}

int main(){
  int T;
  cin >> T;
  while (T--){
    cout << solve() << '\n';
  }
}
