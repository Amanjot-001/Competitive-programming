#include <bits/stdc++.h>
using namespace std;
using lli = long long;

int n, k;
vector<int> arr;

int check(int mid) {
	int cnt=1;
	int prev = arr[0];
	for (int i = 1; i < n; ++i) {
		if(arr[i] >= prev + mid) {
			cnt++;
			prev = arr[i];
		}
	}

	return cnt >= k;
}

void solve() {
	cin >> n >> k;
	arr.resize(n);
	for(int i=0; i<n; i++) cin >> arr[i];
	sort(arr.begin(), arr.end());

	int lo=1, hi=arr[n-1]-arr[0], ans=lo;

	while(lo<=hi) {
		int mid = lo + ((hi-lo) >> 1);
		if(check(mid)) {
			lo=mid+1;
			ans=mid;
		} else {
			hi=mid-1;
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