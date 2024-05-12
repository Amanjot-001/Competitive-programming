#include <bits/stdc++.h>
using namespace std;

int main() {
	int t;
	cin >> t;
	while(t--) {
		int a, b, n;
		cin >> a >> b >> n;
		int arr[n];
		int ans = b;

		for(int i=0; i<n; i++) {
			int temp;
			cin >> temp;
			ans += min(a-1, temp);
		}

		cout << ans << endl;
	}
	return 0;
}
