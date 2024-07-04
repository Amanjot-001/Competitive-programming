#include <bits/stdc++.h>
using namespace std;
using lli = long long;

void solve() {
    int n, q;
	cin >> n >> q;
	vector<lli> a(n+1, 0);

	for(int i=1; i<=n; i++) {
		cin >> a[i];
		a[i] += a[i-1];
	}

	for(int i=1; i<=q; i++) {
		lli l, r, k;
		cin >> l >> r >> k;
		lli ans = a[n] - (a[r] - a[l-1]) + k*(r-l+1);
		if(ans%2 == 1)
			cout << "YES" << '\n';
		else
			cout << "NO" << '\n';
	}

}

signed main() {
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t;
    cin >> t;

    while(t--)
        solve();
    
    return 0;
}
