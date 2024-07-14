#include <bits/stdc++.h>
using namespace std;
using lli = long long;

void solve() {
	int n, m;
	cin >> n >> m;
	vector<pair<int, int>> arr(m);
	unordered_set<int> s;
	for(int i=0; i<m; i++) {
		int x, y;
		cin >> x >> y;
		s.insert(x);
		s.insert(y);
	}

	int center;

	for(int i=1; i<=n; i++) {
		if(s.find(i) == s.end()) {
			center=i;
			break;
		}
	}

	cout << n-1 << '\n';

	for(int i=1; i<=n; i++) {
		if(i != center) {
			cout << center << " " << i << '\n';
		}
	}
}

signed main() {
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	solve();
    return 0;
}