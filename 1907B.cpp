#include <bits/stdc++.h>
using namespace std;

int main() {
  int t;
  cin >> t;
  while (t--) {
    string s;
    cin >> s;

    int n = s.length();
    vector<bool> deleted(n, false);
    vector<int> lower_indices;
    vector<int> upper_indices;

    for (int i = 0; i < n; i++) {
      if (s[i] == 'b') {
        deleted[i] = true;
        if (!lower_indices.empty()) {
          deleted[lower_indices.back()] = true;
          lower_indices.pop_back();
        }
      } 
      else if (s[i] == 'B') {
        deleted[i] = true;
        if (!upper_indices.empty()) {
          deleted[upper_indices.back()] = true;
          upper_indices.pop_back();
        }
      } 
      else {
        if (isupper(s[i])) {
          upper_indices.push_back(i);
        } else {
          lower_indices.push_back(i);
        }
      }
    }

    string output = "";
    for (int i = 0; i < n; i++) {
      if (!deleted[i]) {
        output.push_back(s[i]);
      }
    }

    cout << output << '\n';
  }
  return 0;
}
