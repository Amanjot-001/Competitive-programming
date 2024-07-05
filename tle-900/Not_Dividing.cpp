#include <bits/stdc++.h>
using namespace std;
using lli = long long;

void solve() {
	int n;
	cin >> n;
	vector<lli> arr(n);
	for(int i=0; i<n; i++) {
		cin >> arr[i];
		if(arr[i] == 1)
			arr[i]++;
	}

	for(int i=1; i<n; i++) {
		if(arr[i]%arr[i - 1] == 0){
			arr[i]++;
		}
	}

	for(int i=0; i<n; i++)
		cout << arr[i] << " ";
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