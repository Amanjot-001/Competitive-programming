#include <bits/stdc++.h>
using namespace std;
using lli = long long;

void solve() {
	int n, x;
	cin >> n >> x;
	vector<int> arr(n);
	for(int i=0; i<n; i++) cin >> arr[i];

	int ans=0;
	lli mini=max(0, arr[0]-x), maxi=arr[0]+x;

	for(int i=1; i<n; i++) {
		lli local_mini=max(0, arr[i]-x), local_maxi=arr[i]+x;
		if(mini > local_maxi || local_mini > maxi) {
			ans++;
			mini = local_mini;
			maxi = local_maxi;
		} else {
			mini = max(mini, local_mini);
			maxi = min(maxi, local_maxi);
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