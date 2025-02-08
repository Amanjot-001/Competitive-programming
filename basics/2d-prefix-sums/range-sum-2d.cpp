#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n, m, q;
    cin >> n >> m >> q;
    vector<vector<int>> a(n+1, vector<int>(m+1, 0));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> a[i+1][j+1];
        }
    }

	vector<vector<ll>> p(n+1, vector<ll>(m+1, 0));

	// 2d prefix sums
	for(int i=1; i<=n; i++) {
		for(int j=1; j<=m; j++) {
			p[i][j] = (ll)a[i][j] + p[i-1][j] + p[i][j-1] - p[i-1][j-1];
		}
	}

	while(q--) {
		int x1, y1, x2, y2;
		cin >> x1 >> y1 >> x2 >> y2;

		// cal krke dekho pta lag jaega
		ll res = p[x2][y2] - p[x1-1][y2] - p[x2][y1-1] + p[x1-1][y1-1];
		cout << res << endl;
	}

    return 0;
}