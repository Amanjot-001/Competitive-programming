#include <bits/stdc++.h>
using namespace std;

int main() {
	int t;
	cin >> t;
	while(t--) {
		int n;
		cin >> n;
		vector<int> v(n);
		for(int i=0; i<n; i++)
			cin >> v[i];

		int minFromMax = INT_MAX;
		for(int i=0; i<n-1; i++) {
			int x = max(v[i], v[i+1]);
			minFromMax = min(minFromMax, x);
		}

		cout << minFromMax - 1 << endl;
	}
	return 0;
}
