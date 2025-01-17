#include <bits/stdc++.h>
using namespace std;
#define ll long long

ll w, h, n;

bool check(ll x) {
	return (x/w) * (x/h) >= n;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> w >> h >> n;

	ll l=0, r=1;
	while(!check(r))
		r *= 2;

	while(l+1<r) {
		ll m = l + ((r-l) >> 1);
		if(check(m)) {
			r=m;
		} else {
			l = m;
		}
	}

	cout << r << endl;
	
	return 0;
}