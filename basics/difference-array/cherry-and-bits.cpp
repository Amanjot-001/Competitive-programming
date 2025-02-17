#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	#ifndef ONLINE_JUDGE
		freopen("inputf.txt", "r", stdin);
		freopen("outputf.txt", "w", stdout);
	#endif

	int n, m;
	cin >> n >> m;

	vector<vector<int>> a(n, vector<int>(m));
	for(int i=0; i<n; i++) {
		string s;
		cin >> s;

		for(int j=0; j<m; j++)
			a[i][j] = s[j] == '1' ? 1 : 0;
	}

	vector<vector<int>> d(n+1, vector<int>(m+1, 0));

	int q;
	cin >> q;
	while(q--) {
		int x1, y1, x2, y2;
		cin >> x1 >> y1 >> x2 >> y2;

		x1--, y1--, x2--, y2--;

		d[x1][y1]++;
		d[x2+1][y1]--; // sub 1 to vertical flip
		d[x1][y2+1]--; // sub 1 to horizontal flip
		d[x2+1][y2+1]++; // prevent double subtraction at corners
	}

	// prefix sum
	for(int i=0; i<n; i++) {
		for(int j=0; j<m; j++) {
			if(i>0) d[i][j] += d[i-1][j];
			if(j>0) d[i][j] += d[i][j-1];
			if(i>0 && j>0) d[i][j] -= d[i-1][j-1];
		}
	}

	// checking for flip
	for(int i=0; i<n; i++) {
		for(int j=0; j<m; j++) {
			d[i][j] %= 2;
			if(d[i][j])
				a[i][j] = 1-a[i][j];

			cout << a[i][j];
		}
		cout << endl;
	}


	return 0;
}
