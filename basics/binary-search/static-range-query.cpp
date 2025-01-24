#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int n, q;
	cin >> n >> q;
	vector<int> a(n);
	map<int, vector<int>> mpp;
	for(int i=0; i<n; i++) {
		cin >> a[i];
		mpp[a[i]].emplace_back(i);
	}

	while(q--) {
		int l, r, x;
		cin >> l >> r >> x;

		vector<int>& v = mpp[x];
		int ans = lower_bound(v.begin(), v.end(), r) - lower_bound(v.begin(), v.end(), l);

		cout << ans << endl;
	}

	return 0;
}