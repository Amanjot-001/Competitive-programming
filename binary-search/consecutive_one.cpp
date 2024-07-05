#include <bits/stdc++.h>
using namespace std;
using lli = long long;

int n, k;
vector<int> arr;

bool check(int mid) {
	int cnt=0;
	for(int i=0; i<mid; i++) {
		if(arr[i] == 0)
			cnt++;
	}
	if(cnt <= k)
		return true;

	for(int i=mid; i<n; i++) {
		cnt -= (arr[i-mid] == 0);
		cnt += (arr[i] == 0);
		if(cnt <= k)
			return true;
	}

	return false;
}

void solve() {
	cin >> n >> k;
	arr.resize(n);
	for(int i=0; i<n; i++) cin >> arr[i];

	int lo=k, hi=n, ans=lo;
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