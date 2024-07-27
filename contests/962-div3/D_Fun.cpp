#include <bits/stdc++.h>
using namespace std;
#define ll long long

signed main() {
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	int t;
	cin >> t;

	while(t--) {
		ll n, x;
		cin >> n >> x;

		ll cnt=0;

		for(int a=1; a<=n; a++) {
			for(int b=1; a*b<=n; b++) {
				int ub = min((n-(a*b))/(a+b), (x-a-b));
				if(ub>=1)
					cnt += ub;
			}
		}

		cout << cnt << '\n';
	}
	return 0;
}

