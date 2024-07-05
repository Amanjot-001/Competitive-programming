#include <bits/stdc++.h>
using namespace std;
using lli = long long;

void solve() {
	int n, k;
	cin >> n >> k;
	vector<lli> arr(n);
	for(int i=0; i<n; i++) {
		cin >> arr[i];
	}

	sort(arr.begin(), arr.end());

	int max_cnt=0;
	int cnt=1;
	for(int i=1; i<n; i++) {
		if(arr[i] - arr[i-1] <= k)
			cnt++;
		else {
			max_cnt = max(max_cnt, cnt);
			cnt=1;
		}
	}

	max_cnt = max(max_cnt, cnt);

	cout << n - max_cnt << '\n';
}

signed main() {
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t;
    cin >> t;

    while(t--)
        solve();
    
    return 0;
}