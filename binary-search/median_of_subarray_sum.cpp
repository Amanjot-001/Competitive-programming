#include <bits/stdc++.h>
using namespace std;
using lli = long long;

lli n, k;
vector<lli> arr;

bool check(lli mid) {
	lli cnt=0, sum=0, start=0, curr=0;
	while(curr < n) {
		sum += arr[curr];
		while(start <= curr && sum > mid) {
			sum -= arr[start];
			start++;
		}

		cnt += (curr-start+1);
		curr++;
	}
	return cnt >= k;
}

void solve() {
	cin >> n;
	lli x = (n*(n+1))/2;
	k = (x+1)/2;
	arr.resize(n);
	lli sum=0;
	for(int i=0; i<n; i++) {
		cin >> arr[i];
		sum += arr[i];
	}

	lli lo=0, hi=sum, ans=-1;

	while(lo <= hi) {
		lli mid = lo + ((hi-lo) >> 1);
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