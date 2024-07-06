#include <bits/stdc++.h>
using namespace std;
using lli = long long;

void solve() {
	int n;
	char c;
	string s;
	cin >> n >> c >> s;

	s += s;

	int idx=-1;
	int ans=0;

	for(int i=0; i<2*n; i++) {
		if(s[i] == c && idx == -1)
			idx=i;
		if(s[i] == 'g' && idx != -1) {
			ans = max(ans, i-idx);
			idx=-1;
		}
	}
	cout << ans << '\n';
}

signed main() {
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t;
    cin >> t;

    while(t--)
        solve();
    
    return 0;
}