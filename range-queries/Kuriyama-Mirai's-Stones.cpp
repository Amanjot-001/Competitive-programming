#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main() {
	int n;
	cin >> n;

	vector<int> a(n);
	for(int i=0; i<n; i++)
		cin >> a[i];
	
	vector<int> b = a;
	sort(b.begin(), b.end());

	vector<ll> p(n+1, 0), ps(n+1, 0);
	for(int i=1; i<=n; i++) {
		p[i] = p[i-1] + a[i-1];
		ps[i] = ps[i-1] + b[i-1];
	}

	int q;
	cin >> q;
	while(q--) {
		int t, l, r;
		cin >> t >> l >> r;

		if(t==1) {
			cout << (p[r] - p[l-1]) << endl;
		} else {
			cout << (ps[r] - ps[l-1]) << endl;
		}
	}
	return 0;
}
