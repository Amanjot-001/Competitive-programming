#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main() {
	int n;
	cin >> n;

	vector<int> a(n);
	ll total = 0;
	for(int i=0; i<n; i++) {
		cin >> a[i];
		total += a[i];
	}

	ll ans = 1e11;

	for(int mask=0; mask<(1<<n); mask++) {
		ll sum = 0;
		for(int i=0; i<n; i++) {
			if(mask&(1<<i)) {
				sum += a[i];
			}
		}

		ans = min(ans, abs((total-sum) - sum));
	}

	cout << ans << endl;

	return 0;
}