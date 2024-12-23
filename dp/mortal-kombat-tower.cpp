#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int t;
	cin >> t;
	while(t--) {
		int n;
		cin >> n;
		vector<int> arr(n);
		for(int i=0; i<n; i++)
			cin >> arr[i];

		// 0 my turn, 1 friend turn
		vector<vector<int>> dp(2, vector<int>(n+1, 1e9));

		dp[1][0] = 0; // base case, 0 skips

		for(int j=0; j<n; j++) {
			// switches turn in prev move
			dp[0][j+1] = min(dp[0][j+1], dp[1][j] + arr[j]); // adding if skip or not
			dp[1][j+1] = min(dp[1][j+1], dp[0][j]);

			// switches turn in last 2 move
			if(j+2<=n) {
				dp[0][j+2] = min(dp[0][j+2], dp[1][j] + arr[j] + arr[j+1]);
				dp[1][j+2] = min(dp[1][j+2], dp[0][j]);
			}
		}

		cout << min(dp[0][n], dp[1][n]) << '\n';
	}

	return 0;
}