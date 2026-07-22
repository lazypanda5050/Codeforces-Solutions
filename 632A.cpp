#include <bits/stdc++.h>
using namespace std;

int main(){
  int n,p;
  cin >> n >> p;
  long long apples = 0;
  for (int i = 0; i < n; i++){
    string s;
    cin >> s;
    if (s == "halfplus"){
      apples |= ((long long) 1 << i);
    }
  }

  long long gifts = __builtin_popcountll(apples);
  cout << apples*p - gifts*p/2 << '\n';
}
