#include <bits/stdc++.h>
using namespace std;
#define ll long long

int n, k;
vector<int> a;

bool check(ll x) {
	ll cnt=0;

	for(int i=(n+1)/2-1; i<n; i++) {
		cnt += max(0LL, x-a[i]);
	}

	return cnt<=k;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> n >> k;
	a.resize(n);
	for(int i=0; i<n; i++)
		cin >> a[i];
	sort(a.begin(), a.end());

	ll l=0, r=a[n-1]+k;
	ll ans = 0;
	while(l<=r) {
		ll m = l + ((r-l) >> 1);

		if(check(m)) {
			ans=m;
			l=m+1;
		} else {
			r=m-1;
		}
	}
	
	cout << ans << endl;

	return 0;
}