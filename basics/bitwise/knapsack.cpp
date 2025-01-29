#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main() {
	int n, w;
	cin >> n >> w;

	vector<pair<int, int>> a(n);
	for(int i=0; i<n; i++)
		cin >> a[i].first >> a[i].second;

	int ans = 0;
	for(int mask=0; mask<(1<<n); mask++) {
		int val = 0;
		int weight = 0;
		for(int i=0; i<n; i++) {
			if(mask&(1<<i)) {
				weight += a[i].first;
				val += a[i].second;
			}
		}

		if(weight <= w) {
			ans = max(ans, val);
		}
	}

	cout << ans << endl;

	return 0;
}