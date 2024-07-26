#include <bits/stdc++.h>
using namespace std;

signed main() {
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	int t;
	cin >> t;
	while(t--) {
		int n, k;
		cin >> n >> k;

		vector<vector<int>> grid(n, vector<int>(n));
        for (int i=0; i<n; i++) {
            string row;
            cin >> row;
            for (int j=0; j<n; j++) {
                grid[i][j] = row[j]-'0';
            }
        }

		vector<vector<int>> reduced_grid(n/k, vector<int>(n/k));
        for (int i=0; i<n; i+=k) {
            for (int j=0; j<n; j+=k) {
                reduced_grid[i / k][j / k] = grid[i][j];
            }
        }

        for (auto row : reduced_grid) {
            for (auto cell : row) {
                cout << cell;
            }
            cout << '\n';
        }
	}

	return 0;
}
