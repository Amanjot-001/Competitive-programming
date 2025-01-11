#include <bits/stdc++.h>
using namespace std;

int main() {
	int n;
	cin >> n;
	
	vector<int> a(n);
	for(int i=0; i<n; i++)
		cin >> a[i];

	for(int mask=0; mask < (1<<n); mask++) {
		int ans = 0;
		for(int i=0; i<n; i++) {
			if(mask&(1<<i)) {
				ans += a[i];
			} else {
				ans -= a[i];
			}
		}

		if(ans%360 == 0) {
			puts("YES");
			return 0;
		}
	}

	puts("NO");
	
	return 0;
}
