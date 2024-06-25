#include <bits/stdc++.h>
using namespace std;

int main() {
	int t;
	cin >> t;
	while(t--) {
		long long x, y, k;
		cin >> x >> y >> k;

		int z = y-x%y;
		while(k >= z) {
			k -= z;
			x += z;
			while(x%y == 0)
				x /= y;
			
			z = y-x%y;
			if(x == 1) {
				k %= z;
				break;
			}
		}

		x += k;
        
        cout << x << "\n";
	}
	return 0;
}
