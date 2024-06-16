#include <bits/stdc++.h>
using namespace std;

int main() {
	int t;
	cin >> t;
	while(t--) {
		int n;
		cin >> n;
		int max1=0, max2;

		for(int i=0; i<n-1; i++) {
			int x;
			cin >> x;
			max1 = max(max1, x);
		}
		cin >> max2;
		cout << max1 + max2 << endl;
	}
	return 0;
}
