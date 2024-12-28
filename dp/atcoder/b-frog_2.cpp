#include <bits/stdc++.h>
using namespace std;
#define ll long long

int32_t main() {
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	int n, k;
	cin >> n >> k;
	vector<int> heights(n);
	for(int i=0; i<n; i++)
		cin >> heights[i];
	
	vector<int> dp(n, INT_MAX);
	dp[0]=0;

	for(int i=0; i<n; i++) {
		for(int j=1; j<=k && i+j<n; j++) {
			dp[i+j] = min(dp[i+j], dp[i] + abs(heights[i] - heights[i+j]));
		}
	}

	cout << dp[n-1] << '\n';

	return 0;
}
