#include <bits/stdc++.h>
using namespace std;

int solve(){
  int n,k;
  cin >> n >> k;
  vector<int> a(n);
  for (int i = 0; i < n; i++){
    cin >> a[i];
  }

  sort(a.begin(), a.end());
  vector<int> count = {1};

  for (int i = 1; i < n; i++){
    if (a[i] == a[i-1]){
      count.back()++;
    }
    else{
      count.emplace_back(1);
    }
  }
  sort(count.begin(), count.end());
  int m = count.size();
  for (int i = 0; i < m-1; i++){
    if (count[i] > k){
      return m-i;
    }
    k -= count[i];
  }
  return 1;
}

int main(){
  int T;
  cin >> T;
  while (T--){
    cout << solve() << '\n';
  }
}
