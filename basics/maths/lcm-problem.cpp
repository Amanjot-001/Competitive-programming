#include <bits/stdc++.h>
using namespace std;
#define ll long long

ll lcm(ll a, ll b) {
	return b / gcd(a, b) * a;
}

int main() {
	int t;
	cin >> t;

	while(t--) {
		ll l, r;
		cin >> l >> r;

		if(2*l > r)
			cout << -1 << " " << -1 << endl;
		else {
			ll temp = lcm(l, 2*l);
			cout << l << " " << temp << endl;
		}
	}
	return 0;
}
