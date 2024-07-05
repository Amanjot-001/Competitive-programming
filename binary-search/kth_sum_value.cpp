#include <bits/stdc++.h>
using namespace std;
using lli = long long;

lli n, m, k;
vector<int> arr, brr;

int check(int mid) {
	lli cnt=0;
	for(int i=0; i<n; i++) {
		cnt += upper_bound(brr.begin(), brr.end(), mid - arr[i]) - brr.begin();
	}

	return cnt >= k;
}

void solve() {
	cin >> n >> m >> k;
	arr.resize(n);
	brr.resize(m);
	for(int i=0; i<n; i++) cin >> arr[i];
	for(int i=0; i<m; i++) cin >> brr[i];

	if(n>m) {
		swap(n, m);
		swap(arr, brr);
	}

	sort(arr.begin(), arr.end());
	sort(brr.begin(), brr.end());

	int lo=arr[0]+brr[0];
	int hi=arr[n-1]+brr[m-1];
	int ans=lo;

	while(lo<=hi) {
		int mid = lo + ((hi-lo) >> 1);
		if(check(mid)) {
			hi=mid-1;
			ans=mid;
		} else {
			lo=mid+1;
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