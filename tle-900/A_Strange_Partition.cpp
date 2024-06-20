#include <bits/stdc++.h>
using namespace std;

int main() {
	int t;
	cin >> t;
	while(t--) {
		int n, x;
		cin >> n >> x;

		long long lo = 0, hi = 0;
		for(int i=0; i<n; i++) {
			int num;	
			cin >> num;

			hi += (num+x-1)/x;
			lo += num;
		}

		cout << (lo+x-1)/x << " " << hi << '\n';
	}
	return 0;
}
