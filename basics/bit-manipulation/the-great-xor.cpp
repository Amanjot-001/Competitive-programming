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

	int q;
	cin >> q;
	while(q--) {
		ll n;
		cin >> n;

		ll ans = 0;
		for(int i=0; i<64 && (1LL<<i)<=n; i++) {
			if((n&(1LL<<i)) == 0)
				ans += (1LL<<i);
		}

		cout << ans << endl;
	}

	return 0;
}
