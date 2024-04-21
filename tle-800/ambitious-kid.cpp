#include <bits/stdc++.h>
using namespace std;

int main() {
	int n;
	cin >> n;
	int ans=INT_MAX;
	
	for(int i=0; i<n; i++) {
		int x;
		cin >> x;
		ans=min(ans, abs(x-0));
		if(ans == 0)
			break;
	}

	cout << ans;

	return 0;
}