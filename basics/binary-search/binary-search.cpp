#include <bits/stdc++.h>
using namespace std;

int main() {
	int n, k;
	cin >> n >> k;
	vector<int> a(n);
	for(int i=0; i<n; i++)
		cin >> a[i];
	
	while(k--) {
		int x;
		cin >> x;

		int l=0, r=n-1;
		bool found = false;

		while(l<=r) {
			int m = l + ((r-l) >> 1);
			if(a[m] == x) {
				found = true;
				break;
			} else if(a[m] < x) {
				l = m + 1;
			} else {
				r = m - 1;
			}
		}

		cout << (found ? "YES" : "NO") << endl;
	}

	return 0;
}