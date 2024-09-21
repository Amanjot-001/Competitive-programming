#include<bits/stdc++.h>
using namespace std;
#define ll long long

int32_t main() {
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	int t;
	cin >> t;
	
	for(int i=1; i<=t; i++) {
		int n, k;
		cin >> n >> k;
		
		vector<ll> s(n);
		ll min_time = INT_MAX;
		for(int i=0; i<n; i++) {
			cin >> s[i];
			min_time = min(min_time, s[i]);
		}
		
		ll ans = n==1 ? min_time : min_time*((n-1)*2 - 1);
		if(ans <= k) {
			cout << "Case #" << i << ": " << "YES" << '\n';
		} else {
			cout << "Case #" << i << ": " << "NO" << '\n';
		}
	}

	return 0;
}
