#include <bits/stdc++.h>
using namespace std;
using lli = long long;

void solve() {
	int n, m;
	cin >> n >> m;
	vector<pair<int, int>> edges;

	vector<int> degree(n, 0);

	for(int i=0; i<m; i++) {
		int x, y;
		cin >> x >> y;
		edges.push_back({x, y});

		degree[x-1]++;
		degree[y-1]++;
	}

	int one_deg=0, two_deg=0, gre_deg=0;
	for(int i=0; i<n; i++) {
		if(degree[i] == 1)
			one_deg++;
		else if(degree[i] == 2)
			two_deg++;
		else if(degree[i] > 2)
			gre_deg++;
	}

	if(one_deg==2 && two_deg == n-2)
		cout << "bus topology" << '\n';
	else if(two_deg == n)
		cout << "ring topology" << '\n';
	else if(one_deg==n-1 && gre_deg==1)
		cout << "star topology" << '\n';
	else
		cout << "unknown topology" << '\n';
}

signed main() {
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    solve();

    return 0;
}