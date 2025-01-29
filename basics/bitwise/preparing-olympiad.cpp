#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main() {
	int n, l, r, x;
	cin >> n >> l >> r >> x;

	vector<int> a(n);
	for(int i=0; i<n; i++)
		cin >> a[i];

	int ans = 0;
	for(int mask=0; mask<(1<<n); mask++) {
		int mi=INT_MAX, mx=0;
		ll sum = 0;
		for(int i=0; i<n; i++) {
			if(mask&(1<<i)) {
				mi = min(mi, a[i]);
				mx = max(mx, a[i]);
				sum += a[i];
			}
		}

		if(sum>=l && sum<=r && (mx-mi)>=x && sum > mi)
			ans++;
	}

	cout << ans << endl;
	
	return 0;
}