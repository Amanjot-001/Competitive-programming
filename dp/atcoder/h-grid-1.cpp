#include <bits/stdc++.h>
using namespace std;
#define ll long long

const int mod = 1e9+7;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n, m;
	cin >> n >> m;
	vector<string> grid(n);
	for(int i=0; i<n; i++) 
		cin >> grid[i];
	
	vector<int> dp(m+1, 0);
	dp[1] = 1;

	for(int i=0; i<n; i++) {
		for(int j=1; j<=m; j++) {
			if(grid[i][j-1] == '#') {
				dp[j] = 0;
			} else {
				dp[j] = (dp[j-1] + dp[j]) % mod;
			}
		}
	}

	cout << dp[m] << '\n';

    return 0;
}
