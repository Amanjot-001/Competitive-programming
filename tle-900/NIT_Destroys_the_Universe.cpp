#include <bits/stdc++.h>
using namespace std;
using lli = long long;

void solve() {
	int n;
	cin >> n;
	vector<int> arr(n);
	for(int i=0; i<n; i++) {
		cin >> arr[i];
	}

	if (n == 1) {
        cout << (arr[0] != 0) << '\n';
        return;
    }
	 
	int i=0;
	while(i<n && arr[i] == 0)
		i++;
 
	int j=n-1;
	while(j>=0 && arr[j] == 0)
		j--;
	
	while(i<n && arr[i] != 0)
		i++;
	
	int ans=0;

	if(i>j+1) ans=0;
	else if(i==j+1) ans=1;
	else ans=2;

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