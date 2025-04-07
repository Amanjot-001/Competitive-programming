#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	#ifndef ONLINE_JUDGE
		freopen("inputf.txt", "r", stdin);
		freopen("outputf.txt", "w", stdout);
	#endif

	int t;
	cin >> t;
	while(t--) {
		ll a, b;
		cin >> a >> b;
		ll m = 1e9+7;

		a%=m;
		ll res = 1;
		while(b>0) {
			if(b&1)
				res = res * a % m;
			a = a*a%m;
			b >>= 1;
		}

		cout << res << endl;
	}

	return 0;
}
