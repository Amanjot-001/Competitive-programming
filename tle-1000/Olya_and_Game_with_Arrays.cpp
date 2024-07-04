#include <bits/stdc++.h>
using namespace std;
using lli = long long;

void solve() {
    int n;
	cin >> n;

	int min_val = INT_MAX;
    int smallest_second_min_val = INT_MAX;

	lli sum_of_second_min_vals = 0;

	for(int i=0; i<n; i++) {
		int m;
		cin >> m;

		int local_min_val = INT_MAX;
		int local_sec_min_val = INT_MAX;

		for(int j=0; j<m; j++) {
			int x;
			cin >> x;

			if (x < local_min_val) {
                local_sec_min_val = local_min_val;
                local_min_val = x;
            } else if (x < local_sec_min_val) {
                local_sec_min_val = x;
            }
		}

		sum_of_second_min_vals += local_sec_min_val;
        min_val = min(min_val, local_min_val);
        smallest_second_min_val = min(smallest_second_min_val, local_sec_min_val);
	}

    lli ans = min_val + sum_of_second_min_vals - smallest_second_min_val;

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