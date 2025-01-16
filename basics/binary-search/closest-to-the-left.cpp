#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int n, k;
	cin >> n >> k;
	vector<int> a(n);
	for(int i=0; i<n; i++)
		cin >> a[i];

	while(k--) {
		int x;
		cin >> x;

		int l=-1, r=n;
		while(l+1<r) {
			int m = l + ((r-l) >> 1);

			if(a[m] <= x) {
				l = m;
			} else {
				r = m;
			}
		}

		cout << l + 1 << endl;
	}

	return 0;
}