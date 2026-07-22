#include <bits/stdc++.h>
using namespace std;

int main(){
  long long k,n,w;
  cin >> k >> n >> w;

  int cost = w*(w+1) / 2;
  cost *= k;

  cout << (max(0,cost-n)) << '\n';
}
