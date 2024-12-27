#include <bits/stdc++.h>
using namespace std;
#define ll long long

int32_t main() {
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	int n;
	cin >> n;
	vector<int> heights(n);
	for(int i=0; i<n; i++)
		cin >> heights[i];
	
	vector<int> dp(n, INT_MAX);
	dp[0]=0;

	for(int i=0; i<n; i++) {
		if(i+1 < n)
			dp[i+1] = min(dp[i+1], dp[i] + abs(heights[i] - heights[i+1]));
		if(i+2 < n)
			dp[i+2] = min(dp[i+2], dp[i] + abs(heights[i] - heights[i+2]));
	}

	cout << dp[n-1] << '\n';

	return 0;
}
