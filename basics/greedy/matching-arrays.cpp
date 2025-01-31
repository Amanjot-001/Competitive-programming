#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main() {
    int t;
    cin >> t;

    while (t--) {
		int n, x;
		cin >> n >> x;
		vector<int> a(n), b(n), aid(n), ans(n);
		for(int i=0; i<n; i++)
			cin >> a[i];
		for(int i=0; i<n; i++)
			cin >> b[i];
		
		// sorting a with tracking index
		iota(aid.begin(), aid.end(), 0);
		sort(aid.begin(), aid.end(), [&] (int l, int r) { return a[l] < a[r]; });
		// sorting b
		sort(b.begin(), b.end());

		// x smallest b[i] to largest a[i];
		for(int i=0; i<x; i++)
			ans[aid[n-x+i]] = b[i];
		
		// remaining
		for(int i=x; i<n; i++)
			ans[aid[i-x]] = b[i];

		// checking if beauty == x
		for(int i=0; i<n; i++)
			x -= a[i]>ans[i];

		if(x==0) {
			cout << "YES" << endl;
			for(int i=0; i<n; i++)
				cout << ans[i] << " ";
			cout << endl;
		} else {
			cout << "NO" << endl;
		}
	}

	return 0;
}