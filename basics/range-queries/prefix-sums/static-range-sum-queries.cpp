#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main() {
	int n, q;
	cin >> n >> q;

	vector<int> a(n);
	for(int i=0; i<n; i++){
		cin >> a[i];
	}

	vector<ll> p(n+1, 0);

	for(int i=1; i<=n; i++) {
		p[i] = p[i-1] + a[i-1];
	}

	for(int i=0; i<q; i++) {
		int l, r;
		cin >> l >> r;

		cout << (p[r] - p[l-1]) << endl;
	}

	return 0;
}
