#include <bits/stdc++.h>
using namespace std;
#define ll long long

ll n;

bool check(ll m) {
	ll cnt = 0;
	for(int i=1; i<=n; i++) {
		cnt += min(n, m/i);
	}

	return cnt >= (n*n + 1)/2;
}
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> n;

	ll l=1, r=n*n;

	while(l+1<r) {
		ll m = l + ((r-l) >> 1);

		if(check(m)) {
			r=m;
		} else {
			l=m;
		}
	}

	cout << r << endl;

	return 0;
}