#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int n, q;
	cin >> n >> q;
	vector<ll> a(n+1, 0);
	for(int i=1; i<=n; i++)	
		cin >> a[i];

	vector<int> ops(n+2, 0);
	for(int i=0; i<q; i++) {
		int l, r;
		cin >> l >> r;
		ops[l]++;
		ops[r+1]--;
	}

	for(int i=1; i<=n; i++)
		ops[i] += ops[i-1];

	sort(a.rbegin(), a.rend());
	sort(ops.rbegin(), ops.rend());

	ll ans = 0;
	for(int i=0; i<n; i++) {
		ans += a[i]*(ll)ops[i];
	}

	cout << ans << endl;

	return 0;
}