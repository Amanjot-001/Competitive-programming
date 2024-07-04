#include <bits/stdc++.h>
using namespace std;
using lli = long long;

void solve() {
    int n;
	cin >> n;
	string s;
	cin >> s;

	int ans=1;
	int x=1;
	for(int i=1; i<n; i++) {
		if(s[i] == s[i-1])
			x++;
		else
			x=1;
		ans=max(ans, x);
	}

	cout << ans + 1 << '\n';
}

signed main() {
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t;
    cin >> t;

    while(t--)
        solve();
    
    return 0;
}