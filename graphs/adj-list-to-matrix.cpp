#include <bits/stdc++.h>
using namespace std;
using lli = long long;

void solve() {
	int n;
	cin >> n;
	vector<int> adj[n];
	vector<vector<int>> mat(n, vector<int> (n, 0));

	for(int i=0; i<n; i++) {
		int x;
		cin >> x;
		adj[i].push_back(x);
		cin >> x;
		adj[i].push_back(x);
		for(int j=0; j<adj[i][1]; j++) {
			cin >> x;
			adj[i].push_back(x);
			mat[i][adj[i][j+2]-1] = 1;
		}
	}

	for(int i=0; i<n; i++) {
		for(int j=0; j<n; j++) {
			cout << mat[i][j] << " ";
		}
		cout << '\n';
	}
}

signed main() {
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    solve();

    return 0;
}