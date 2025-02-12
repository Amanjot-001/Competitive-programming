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
		int n, m, k;
		cin >> n >> m >> k;

		vector<vector<int>> a(n+1, vector<int>(m+1, 0));
		vector<string> s(n);
    	vector<vector<int>> p(n + 1, vector<int>(m + 1, 0)); // prefix of no. of 1 mountains

		for(int i=1; i<=n; i++)
			for(int j=1; j<=m; j++)
				cin >> a[i][j];

		for(int i=0; i<n; i++)
			cin >> s[i];

		ll diff = 0;
		for(int i=1; i<=n; i++) {
			int curr=0;
			for(int j=1; j<=m; j++) {
				if(s[i-1][j-1] == '1') {
					curr++;
					diff += (ll)a[i][j];
				} else {
					diff -= (ll)a[i][j];
				}

				// no of 1 cells in i,j matrix
				p[i][j] = p[i-1][j] + p[i][j-1] -p[i-1][j-1] + (s[i-1][j-1] - '0');
			}
		}

		if(diff == 0) {
			cout << "YES" << endl;
			continue;
		}

		// k*k has x 1's cells
		// then 0's cells => k*k - x
		// need abs diff for eq, hence f is cal
		int g = 0;
		for(int i=1; i<=n-k+1; i++) {
			for(int j=1; j<=m-k+1; j++) {
				int f = p[i+k-1][j+k-1] - p[i-1][j+k-1] - p[i+k-1][j-1] + p[i-1][j-1];
				f = abs(k*k -2*f);
				g = gcd(g, f);
			}
		}

		if (g == 0 || diff % g != 0) 
			cout << "NO" << endl;
		else 
			cout << "YES" << endl;
	}

	return 0;
}