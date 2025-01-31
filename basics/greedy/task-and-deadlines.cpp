#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int n;
	cin >> n;
	vector<pair<int, int>> a(n);
	for(int i=0; i<n; i++)
		cin >> a[i].first >> a[i].second;

	sort(a.begin(), a.end());

	ll ans = 0;
	ll finish = 0;
	for(int i=0; i<n; i++) {
		finish += a[i].first;
		ans += (a[i].second - finish);
	}

	cout << ans << endl;

	return 0;
}