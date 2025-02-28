#include <bits/stdc++.h>
#include <bit>
using namespace std;
#define ll long long

// tle, need segment trees

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	#ifndef ONLINE_JUDGE
		freopen("inputf.txt", "r", stdin);
		freopen("outputf.txt", "w", stdout);
	#endif

	int n;
	cin >> n;
	vector<int> a(n);
	vector<bitset<20>> v(n);
	for(int i=0; i<n; i++) {
		int x;
		cin >> x;
		v[i] = bitset<20>(x);
	}

	int m;
	cin >> m;
	while(m--) {
		int t;
		cin >> t;

		if(t==1) {
			int l, r;
			cin >> l >> r;
			l--, r--;

			ll sum = 0;
			for(int i=l; i<=r; i++) {
				for(int j=0; j<20; j++)
					if(v[i][j])
						sum += (1<<j);
			}

			cout << sum << endl;
		} else {
			int l, r, x;
			cin >> l >> r >> x;
			l--, r--;

			for(int i=l; i<=r; i++) {
				for(int j=0; j<20; j++) {
					if(x&(1<<j))
						v[i][j] = v[i][j] ? 0 : 1;
				}
			}
		}
	}

	return 0;
}
