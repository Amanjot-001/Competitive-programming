#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int n, m, k;
	cin >> n >> m >> k;
	vector<ll> a(n+1, 0), l(m+1, 0), r(m+1, 0), d(m+1, 0);
	for(int i=1; i<=n; i++)
		cin >> a[i];

	for(int i=1; i<=m; i++) 
		cin >> l[i] >> r[i] >> d[i];

	vector<ll> ops(m+2, 0);
	for(int i=0; i<k; i++) {
		int x, y;
		cin >> x >> y;
		ops[x]++;
		ops[y+1]--;
	}
	for(int i=1; i<=m; i++) {
		ops[i] += ops[i-1];
	}

	vector<ll> aux(n+2, 0);
	for(int i=1; i<=m; i++) {
		ll times = ops[i];
		aux[l[i]] += times * d[i];
		aux[r[i]+1] -= times * d[i];
	}

	for(int i=1; i<=n; i++) {
		aux[i] += aux[i-1];
		a[i] += aux[i];
	}

	for(int i=1; i<=n; i++)
		cout << a[i] << " ";

	cout << endl;

	return 0;
}