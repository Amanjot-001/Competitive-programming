#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int n, x;
	cin >> n >> x;
	
	ll p = 0;
	map<ll, int> sums; // unordered map cause collision because of ll
	sums[0] = 1;

	ll ans = 0;

	for(int i=0; i<n; i++) {
		int a;
		cin >> a;

		p += a;

		ans += sums[p - x];
		sums[p]++;
	}

	cout << ans << endl;

	return 0;
}
