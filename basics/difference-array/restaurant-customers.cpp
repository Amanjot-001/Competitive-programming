#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int n;
	cin >> n;
	vector<pair<int, int>> a;
	for(int i=0; i<n; i++) {
		int l, r;
		cin >> l >> r;

		a.push_back({l, 1});
		a.push_back({r, -1});
	}

	sort(a.begin(), a.end());
	int curr = 0, ans = 0;

	for(auto it: a) {
		curr += it.second;
		ans = max(ans, curr);
	}

	cout << ans << endl;

	return 0;
}