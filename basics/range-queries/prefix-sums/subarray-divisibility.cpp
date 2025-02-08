#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int n;
	cin >> n;

	vector<int> sums(n);
	ll p = 0;
	sums[0] = 1;

	for(int i=0; i<n; i++) {
		int a;
		cin >> a;

		p+=a;
		sums[(p%n + n) % n]++;
	}

	ll ans = 0;
	for(int i=0; i<n; i++) {
		ll x = sums[i];
		ans += (x*(x-1)/2);
	}

	cout << ans << endl;

	return 0;
}
