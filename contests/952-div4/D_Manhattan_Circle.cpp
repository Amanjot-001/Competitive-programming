#include <bits/stdc++.h>
using namespace std;

int main() {
	int t;
	cin >> t;
	while(t--) {
		int n, m;
		cin >> n >> m;

		vector<vector<int>> dp(n, vector<int> (m));
		int maxPt=0, x=0, y=0;
		for(int i=0; i<n; i++) {
			for(int j=0; j<m; j++) {
				char ch;
				cin >> ch;
				if (ch == '#') {
                    if (i == 0 || j == 0) {
                        dp[i][j] = 1;
                    } else {
                        dp[i][j] = min(dp[i-1][j], dp[i][j-1]) + 1;
                    }
                } else {
                    dp[i][j] = 0;
                }
				if(dp[i][j] > maxPt) {
					maxPt = dp[i][j];
					x=i;
					y=j;
				}
			}
		}

		cout << x+1 << " " << y+1 << endl;
	}
	return 0;
}

