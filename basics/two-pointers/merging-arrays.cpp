#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int n, m;
	cin >> n >> m;
	vector<int> a(n), b(m), c(n+m);
	for(int i=0; i<n; i++)
		cin >> a[i];
	for(int i=0; i<m; i++)
		cin >> b[i];

	int i=0, j=0;
	while(i < n || j < m) {
		if(j==m || i<n && a[i] < b[j]) {
			c[i+j] = a[i];
			i++;
		} else {
			c[i+j] = b[j];
			j++;
		}
	}

	for(auto x: c)
		cout << x << " ";
	cout << endl;

	return 0;
}