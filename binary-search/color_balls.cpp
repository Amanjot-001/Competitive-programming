#include <bits/stdc++.h>
using namespace std;
using lli = long long;

int n, k;
vector<int> arr;
unordered_map<int, int> freq;

bool check(int mid) {
	int totalUsefulBalls=0;
	for(auto &it: freq) {
		totalUsefulBalls += min(it.second, mid);
	}

	return totalUsefulBalls >= k*mid;
}

void solve() {
	cin >> n >> k;
	arr.resize(n);
	for(int i=0; i<n; i++) {
		cin >> arr[i];
		freq[arr[i]]++;
	}

	int lo=0, hi=n/k, ans=0;

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
	freq.clear();
}

signed main() {
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t;
    cin >> t;

    while(t--)
        solve();
    
    return 0;
}