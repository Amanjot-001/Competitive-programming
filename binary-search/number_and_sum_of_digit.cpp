#include <bits/stdc++.h>
using namespace std;
using lli = long long;

lli n, s;

bool check(lli mid) {
	lli temp=mid;
	lli sumOfDigits=0;
	while(temp>0) {
		sumOfDigits += temp%10;
		temp /= 10;
	}

	return (mid-sumOfDigits) >= s;
}

void solve() {
	cin >> n >> s;

	lli lo=1, hi=n, ans=0;

	while(lo<=hi) {
		lli mid = lo + ((hi-lo) >> 1);
		if(check(mid)) {
			hi=mid-1;
		} else {
			ans=mid; // cause we need pt where condition starts failing
			lo=mid+1;
		}
	}

	cout << n-ans << '\n';
}

signed main() {
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t;
    cin >> t;

    while(t--)
        solve();
    
    return 0;
}