#include <bits/stdc++.h>
using namespace std;

int main() {
	int t;
	cin >> t;

	while(t--) {
		int n;
		cin >> n;

		unsigned int ans = 0;
		for(int i=0; i<32; i++) {
			ans <<= 1;
			ans |= (n&1);
			n >>= 1;
		}

		cout << ans << endl;
	}

	return 0;
}
