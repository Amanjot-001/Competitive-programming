#include <bits/stdc++.h>
using namespace std;
using lli = long long;

void solve() {
	int n, k;
	cin >> n >> k;

	int break_sum=0;
	int total_1s=0;
	int max_val=-1;

	for(int i=0; i<k; i++) {
		int x;
		cin >> x;
		max_val = max(max_val, x);
		break_sum += x-1;
		total_1s += x;
	}

	int ans = break_sum + total_1s - (max_val-1) - max_val;

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