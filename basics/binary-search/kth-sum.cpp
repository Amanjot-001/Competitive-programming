#include <bits/stdc++.h>
using namespace std;
#define ll long long

int n, k;
vector<ll> a, b;

bool check(ll x) {
	ll cnt = 0;
	for(int i=0; i<n; i++) {
		cnt += upper_bound(b.begin(), b.end(), x - a[i]) - b.begin();
	}

	return cnt >= k;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> n >> k;
	a.resize(n), b.resize(n);

	for(int i=0; i<n; i++)
		cin >> a[i];
	for(int i=0; i<n; i++)
		cin >> b[i];

	sort(a.begin(), a.end()), sort(b.begin(), b.end());

	ll l = a[0]+b[0], r = a[n-1]+b[n-1];
	ll ans = 0;
	while(l<=r) {
		ll m = l + ((r-l) >> 1);

		if(check(m)) {
			ans = m;
			r=m-1;
		} else {
			l=m+1;
		}
	}

	cout << ans << endl;

	return 0;
}