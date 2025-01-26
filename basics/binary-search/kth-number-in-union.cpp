#include <bits/stdc++.h>
using namespace std;
#define ll long long

int n, k;
vector<ll> a, b;

bool check(ll x) {
	ll cnt = 0;
	for(int i=0; i<n; i++) {
		cnt += max(0LL, min(b[i], x) - a[i] + 1);
	}

	return cnt > k;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> n >> k;
	a.resize(n), b.resize(n);
	ll minEle = 2e9;
	ll maxEle = -2e9;
	for(int i=0; i<n; i++) {
		cin >> a[i] >> b[i];
		minEle = min(minEle, min(a[i], b[i]));
		maxEle = max(maxEle, max(a[i], b[i]));
	}
	
	ll l=minEle, r=maxEle;
	ll ans = 0;
	while(l<=r) {
		ll m = l + ((r-l) >> 1);
		if(check(m)) {
			ans=m;
			r=m-1;
		} else {
			l=m+1;
		}
	}

	cout << ans << endl;

	return 0;
}