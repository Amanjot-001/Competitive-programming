#include <bits/stdc++.h>
using namespace std;

int main() {
	int t;
	cin >> t;
	while(t--) {
		int n;
		cin >> n;
		int ans=0;
		for(int i=0; i<n-1; i++) {
			int x;
			cin >> x;
			ans+=x;
		}
		
		// total effeciency has to be 0
		cout << -ans << endl;
	}
	return 0;
}