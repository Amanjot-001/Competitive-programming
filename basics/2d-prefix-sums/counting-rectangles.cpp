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
		int n, q;
		cin >> n >> q;

		vector<vector<ll>> a(1001, vector<ll>(1001, 0));
		vector<vector<ll>> p(1001, vector<ll>(1001, 0));
		for(int i=0; i<n; i++) {
			int h, w;
			cin >> h >> w;
			a[h][w] += (ll)h*w;
		}

		for(int i=1; i<1001; i++) {
			for(int j=1; j<1001; j++) {
				p[i][j] = p[i-1][j] + p[i][j-1] - p[i-1][j-1] + a[i][j];
			}
		}

		while(q--) {
			int hs, ws, hb, wb;
			cin >> hs >> ws >> hb >> wb;

			// since hs < h < hb and ws < w < wb
			// so changed how res should be calculated
			ll res = p[hb-1][wb-1] - p[hs][wb-1] - p[hb-1][ws] + p[hs][ws];
			cout << res << endl;
		}
	}

    return 0;
}