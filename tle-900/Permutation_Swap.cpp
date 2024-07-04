#include <bits/stdc++.h>
using namespace std;
using lli = long long;

void solve() {
    int n;
	cin >> n;
	vector<int> p(n);
	for(int i=0; i<n; i++)  {
		cin >> p[i];
		p[i] = abs(i-p[i]+1);
	}

	for(int i=1; i<n; i++) {
		p[i] = __gcd(p[i], p[i-1]);
	}

	cout << p[n-1] << '\n';
}

signed main() {
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t;
    cin >> t;

    while(t--)
        solve();
    
    return 0;
}