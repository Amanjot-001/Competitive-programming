#include <bits/stdc++.h>
using namespace std;

int main() {
	int t;
	cin >> t;
	while (t--) {
		long long h, n;
		cin >> h >> n;
		vector<long long> a(n);
		vector<long long> c(n);
		for(int i=0; i<n; i++)
			cin >> a[i];
		for(int i=0; i<n; i++)
			cin >> c[i];

		for (int i = 0; i < n; i++)
            h -= a[i];
		
		if(h<=0) {
			cout << 1 << '\n';
			continue;
		}

		long long l = 0, r = 1e12, ans = 0;
		while(l <= r) {
			long long mid = (l+r) >> 1;
			long long sum = 0;
			for (int i = 0; i < n; i++) {
				sum += (mid/ c[i]) * a[i];
				if (sum >= h) break;
			}

			if(sum >= h) {
				r = mid-1;
				ans = mid;
			}
			else
				l = mid+1;
		}

		cout << ans+1 << '\n';
	}
	return 0;
}
