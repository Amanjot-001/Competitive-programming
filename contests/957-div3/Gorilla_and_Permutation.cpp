#include <bits/stdc++.h>
using namespace std;
using lli = long long;

void solve() {
	int n, m, k;
	cin >> n >> m >> k;
	
	for(int i=n; i>=k; i--)
		cout << i << " ";
	
	for(int i=m+1; i<k; i++)
		cout << i << " ";
	
	for(int i=1; i<=m; i++)
		cout << i << " ";

	cout << '\n';
}

signed main() {
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t;
    cin >> t;

    while(t--)
        solve();
    
    return 0;
}