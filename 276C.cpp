#include <bits/stdc++.h>
using namespace std;

int main(){
    cin.tie(0)->sync_with_stdio(false);
    
    int n, q;
    cin >> n >> q;

    vector<long long> a(n);
    for (int i = 0; i < n; i++){
        cin >> a[i];
    }

    vector<long long> diff(n + 1, 0);

    for (int i = 0; i < q; i++){
        int l, r;
        cin >> l >> r;
        l--; r--; 
        
        diff[l]++;
        if (r + 1 < n) {
            diff[r + 1]--;
        }
    }

    vector<long long> freq(n, 0);
    long long current_freq = 0;
    for (int i = 0; i < n; i++) {
        current_freq += diff[i];
        freq[i] = current_freq;
    }

    sort(a.begin(), a.end());
    sort(freq.begin(), freq.end());

    long long ans = 0;
    for (int i = 0; i < n; i++){
        ans += a[i] * freq[i];
    }

    cout << ans << '\n';

    return 0;
}