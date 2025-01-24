#include <bits/stdc++.h>
using namespace std;
#define ll long long


int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int t;
	cin >> t;

	while(t--) {
		int l, r;
		cin >> l >> r;
		ll ans = 0;

		while(l<r) {
			ans += r-l;
			l /= 10;
			r /= 10;
		}

		cout << ans << endl;
	}

	return 0;
}