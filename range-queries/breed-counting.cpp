#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	freopen("bcount.in", "r", stdin);
    freopen("bcount.out", "w", stdout);

	int n, q;
	cin >> n >> q;
	vector<int> a(n);
	for(int i=0; i<n; i++)
		cin >> a[i];

	vector<vector<int>> p(n+1, vector<int>(3, 0));
	for(int i=1; i<=n; i++) {
		p[i] = p[i-1];
		p[i][a[i-1]-1]++;
	}

	while(q--) {
		int l, r;
		cin >> l >> r;

		int breed1 = p[r][0] - p[l-1][0];
		int breed2 = p[r][1] - p[l-1][1];
		int breed3 = p[r][2] - p[l-1][2];

		cout << breed1 << " " << breed2 << " " << breed3 << endl;
	}

	return 0;
}
