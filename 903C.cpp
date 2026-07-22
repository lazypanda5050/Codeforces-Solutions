#include <bits/stdc++.h>
using namespace std;

int main(){
  int n;
  cin >> n;
  unordered_map<int, int> mp;

  int t;
  for (int i = 0; i < n; i++){
    cin >> t;
    mp[t]++;
  }

  int ans = -1;
  for (const auto& [key, value] : mp){
    ans = max(ans, value);
  }

  cout << ans << '\n';
}
