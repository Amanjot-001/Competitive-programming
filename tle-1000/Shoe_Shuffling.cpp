#include <bits/stdc++.h>
using namespace std;
using lli = long long;

void solve() {
	int n;
	cin >> n;
	vector<int> arr(n), v(n);
	for(int i=0; i<n; i++) cin >> arr[i];
	for(int i=0; i<n; i++) v[i] = i+1;

	if(n == 1) {
		cout << -1 << '\n';
		return;
	}

	for(int i=0; i<n-1; i++) {
		if(arr[i] == arr[i+1])
			swap(v[i], v[i+1]);
	}

	for(int i=0; i<n; i++) {
		if(v[i] == i+1) {
			cout << -1 << '\n';
			return;
		}
	}

	for(int i=0; i<n; i++) {
		cout << v[i] << " ";
	}
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