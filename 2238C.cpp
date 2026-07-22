#include <bits/stdc++.h>
using namespace std;

const int MAXN = 2e5;
int n;
vector<vector<int>> p;
int ans[MAXN], dp[MAXN], depth[MAXN];

void dfs(int cur, int prev){
  ans[cur] = 0;
  dp[cur] = depth[cur];
  int m1 = depth[cur], m2 = depth[cur];
  for (auto nxt : p[cur]){
    if (nxt != prev){
      depth[nxt] = depth[cur]+1;
      dfs(nxt,cur);
      dp[cur] = max(dp[nxt],dp[cur]);
      ans[cur] += ans[nxt];
      if (dp[nxt] >= m1){
        m2 = m1;
        m1 = dp[nxt];
      }
      else if (dp[nxt] >= m2){
        m2 = dp[nxt];
      }
    }
  }
  ans[cur] += m2-depth[cur]+1;
}
int main(){
  int T;
  cin >> T;
  while (T--){
    cin >> n;
    p.resize(n);
    for (int i = 1; i < n; i++){
      int a;
      cin >> a;
      p[a-1].push_back(i);
    }

    dfs(0,-1);
    cout << ans[0] << '\n';
    for (int i = 0; i < n; i++){
      p[i].clear();
    }
  }
}
