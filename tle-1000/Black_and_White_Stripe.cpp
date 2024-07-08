#include <bits/stdc++.h>
using namespace std;
using lli = long long;

void solve() {
	int n, k;
	string s;
	cin >> n >> k >> s;

	int i=0, j=0, curr=0;
	int ans = INT_MAX;

	while(i<=j && j<n) {
		char ch = s[j];

		if(ch == 'W') {
			curr++;
		}

		if(j-i+1 == k) {
			ans=min(ans, curr);
		}
		
		if(j-i+1 >= k) {
			if(s[i] == 'W')
				curr--;
			j++;
			i++;
		} else {
			j++;
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