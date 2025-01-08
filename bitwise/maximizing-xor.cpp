#include <bits/stdc++.h>
using namespace std;

int main() {
	int l, r;
	cin >> l >> r;
	
	int ans = 0;

	for(int i=l; i<=r; i++) {
		for(int j=i; j<=r; j++) {
			ans = max(ans, i^j);
		}
	}	

	cout << ans << endl;

	return 0;
}