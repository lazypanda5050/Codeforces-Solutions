#include <bits/stdc++.h>
using namespace std;

int main(){
	// sort the array (increasing)
	// keep array of frequencies (how many times used)
	// sort second array (increasing)
	// ans += a1[i]*a2[i]

	int n,q;
	cin >> n >> q;

	int a[n];
	for (int i = 0; i < n; i++){
		cin >> a[i];
	}

	sort(a,a+n);

	int queries[q][2];

	for (int i = 0; i < q; i++){
		cin >> queries[i][0] >> queries[i][1];
	}

	int freq[n+1] = { 0 };

	for (int i = 0; i < q; i++){
		freq[queries[i][0]-1]++; // 1 indexed -> 0 indexed
		freq[queries[i][1]]--;
	}

	for (int i = 1; i < n+1; i++){
		freq[i] += freq[i-1];
	}

	sort(freq,freq+n);

	int ans = 0;

	for (int i = 0; i < n; i++){
		ans += a[i]*freq[i];
	}

	cout << ans << '\n';

	return 0;
}

// x x
//   x x
// x x x
