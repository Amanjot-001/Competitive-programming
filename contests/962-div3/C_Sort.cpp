#include <bits/stdc++.h>
using namespace std;

signed main() {
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	int t;
	cin >> t;
	while(t--) {
		int n, q;
		string a, b;
		cin >> n >> q >> a >> b;

		vector<vector<int>> freqA(n+1, vector<int>(26, 0));
		vector<vector<int>> freqB(n+1, vector<int>(26, 0));

		for(int i=0; i<n; i++) {
			for(int j=0; j<26; j++) {
				freqA[i+1][j] = freqA[i][j];
				freqB[i+1][j] = freqB[i][j];
			}
			freqA[i+1][a[i]-'a']++;
			freqB[i+1][b[i]-'a']++;
		}

		for(int i=0; i<q; i++) {
			int l, r;
			cin >> l >> r;
			l--;

			int ans=0;
			for(int j=0; j<26; j++) {
				int cntA = freqA[r][j]-freqA[l][j];
				int cntB = freqB[r][j] - freqB[l][j];
				ans += abs(cntA-cntB);
			}

			cout << ans/2 << '\n';
		}
	}

	return 0;
}
