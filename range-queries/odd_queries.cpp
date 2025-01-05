#include <bits/stdc++.h>
using namespace std;

int main() {
	int t;
	cin >> t;

	while(t--) {
		int n, q;
		cin >> n >> q;

		vector<int> a(n);
		for(int i=0; i<n; i++)
			cin >> a[i];
		
		vector<int> p(n+1, 0);
		for(int i=1; i<=n; i++)
			p[i] = p[i-1] + a[i-1];
		
		while(q--) {
			int l, r, k;
			cin >> l >> r >> k;

			int x = p[n] - (p[r] - p[l-1]);
			x += (r-l+1)*k;

			if((x&1) == 0)
				cout << "NO" << endl;
			else
				cout << "YES" << endl;
		}
	}

	return 0;
}
