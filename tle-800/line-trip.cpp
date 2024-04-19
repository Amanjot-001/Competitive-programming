#include <bits/stdc++.h>
using namespace std;

int main() {
	int t;
	cin >> t;
	while(t--) {
		int n, x;
		cin >> n >> x;
		int arr[n];
    		for(int &it: arr)
        		cin >> it;
		int ans = 0, prev = 0;
		for(int i=0; i<n; i++) {
			ans = max(ans, arr[i] - prev);
			prev = arr[i];		
		}
		ans = max(ans, 2*(x - prev));
		cout << ans << endl;
	}
	return 0;
}
