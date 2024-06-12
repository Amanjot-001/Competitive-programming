#include <bits/stdc++.h>
using namespace std;

int main() {
	int t;
	cin >> t;
	while(t--) {
		long long x, y, z, k;
		cin >> x >> y >> z >> k;
		long long ans = 0;

		for(long long i=1; i<=x; i++) {
			for(long long j=1; j<=y; j++) {
				if(k % (i*j)) continue;
				long long a = k/(i*j);
				ans = max(ans, (x-i+1) * (y-j+1) * (z-a+1));
			}
		}

		cout << ans << endl;
	}
	return 0;
}
