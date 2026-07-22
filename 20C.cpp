#include <bits/stdc++.h>
#define ll long long
#define p pair<ll, ll>
using namespace std;

int main(){
  cin.tie(0)->sync_with_stdio(false);

  ll n,m;
  cin >> n >> m;
  vector<vector<p>> adj(n);

  for (ll i = 0; i < m; i++){
    ll a,b,w;
    cin >> a >> b >> w;
    a--,b--;
    adj[a].push_back({w,b});
    adj[b].push_back({w,a});
  }

  vector<ll> dist(n, LLONG_MAX);
  dist[0] = 0;

  vector<bool> visited(n, false);
  priority_queue<p, vector<p>, greater<p>> pq;

  pq.push({0,0});
  while (!pq.empty()){
    auto [_, node] = pq.top(); pq.pop(); // distance is unused

    if (visited[node]){
      continue;
    }

    visited[node] = true;

    for (p neighbor : adj[node]){
      if (dist[node] + neighbor.first < dist[neighbor.second]){
        dist[neighbor.second] = dist[node]+neighbor.first;
        pq.push({dist[neighbor.second], neighbor.second});
      }
    }
  }

  if (dist[n-1] == LLONG_MAX){
    cout << -1 << '\n';
  }
  else{
    vector<ll> path;
    ll cur = n-1;
    path.push_back(cur+1);
    while (cur != 0){
      for (p node : adj[cur]){
        if (dist[cur] - node.first == dist[node.second]){
          cur = node.second;
          path.push_back(cur+1);
          break;
        }
      }
    }
    reverse(path.begin(), path.end());
    for (ll node : path){
      cout << node << ' ';
    }
    cout << '\n';
  }
}
