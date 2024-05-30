#include <bits/stdc++.h>
using namespace std;

int main() {
	int t;
	cin >> t;
	while(t--) {
		int n;
		cin >> n;
		int a[n], b[n+1];
		for(auto &it: a)
			cin >> it;
		for(auto &it: b)
			cin >> it;

		int diff = INT_MAX;
		bool flag = false;
		
		long long ans =1;
		for(int i=0; i<n; i++) {
			ans += abs(a[i] - b[i]);
			diff = min(diff, abs(a[i] - b[n]));
			diff = min(diff, abs(b[i] - b[n]));
			if((a[i] <= b[n] && b[i] >= b[n]) || (a[i] >= b[n] && b[i] <= b[n]))
				flag = true;
		}

		if(!flag)
			ans += diff;

		cout << ans << endl;
	}
	return 0;
}
	