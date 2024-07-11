#include <bits/stdc++.h>
using namespace std;
using lli = long long;
using lld = long double;

int n, k;
vector<int> arr, brr;

bool check(lld mid) {
	priority_queue<lld, vector<lld>, greater<lld>> pq;
	for(int i=0; i<n; i++) {
		pq.push(arr[i]-mid*brr[i]);
		if(pq.size()>k)
			pq.pop();
	}

	lld s = 0.0;
	while(pq.size()){
		s += pq.top();
		pq.pop();
	}		

	return s >= 0.0;
}

void solve() {
	cin >> n >> k;
	arr.resize(n);
	brr.resize(n);
	lld sum=0;
	for(int i=0; i<n; i++) {
		cin >> arr[i];
		sum += arr[i];
	}
	for(int i=0; i<n; i++)
		cin >> brr[i];

	lld lo=0.0, hi=1e8, ans=0.0;

	while(abs(hi-lo) > 1e-9) {
		lld mid = (hi+lo)/2.0;
		if(check(mid)) {
			lo=mid;
			ans=mid;
		} else {
			hi=mid;
		}
	}

    cout<<fixed<<setprecision(6)<<ans<<"\n"; // to output exaclty 6 fixed pts after decimal
}

signed main() {
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t;
    cin >> t;

    while(t--)
        solve();
    
    return 0;
}