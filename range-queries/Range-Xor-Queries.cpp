#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int n, q;
	cin >> n >> q;
	vector<int> a(n), p(n+1, 0);
	for(int i=0; i<n; i++) {
		cin >> a[i];
	}

	for(int i=1; i<=n; i++) {
		p[i] = p[i-1]^a[i-1];
	}

	while(q--) {
		int l, r;
		cin >> l >> r;

		cout << (p[r] ^ p[l-1]) << endl;
	}

	return 0;
}
