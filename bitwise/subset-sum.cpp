#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main() {
	int n, s;
	cin >> n >> s;
	vector<int> a(n);
	for(int i=0; i<n; i++)
		cin >> a[i];

	// 0 to 2^n-1 subsets
	for(int mask=0; mask < (1<<n); mask++) {
		ll sum = 0;

		// 1 means taken, 0 not taken
		for(int i=0; i<n; i++) {
			if(mask & (1<<i))
				sum += a[i];
		}

		if(sum == s) {
			cout << "yes" << endl;
			return 0;
		}
	}

	cout << "no" << endl;
	
	return 0;
}
