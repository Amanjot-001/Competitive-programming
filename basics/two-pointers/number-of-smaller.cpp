#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int n, m;
	cin >> n >> m;
	vector<int> a(n), b(m), c(m);
	for(int i=0; i<n; i++)
		cin >> a[i];
	for(int i=0; i<m; i++)
		cin >> b[i];


	for(int i=0, j=0; j<m; j++) {
		while(i<n && a[i] < b[j])
			i++;
		c[j] = i;
	}

	for(auto x: c)
		cout << x << " ";
	cout << endl;

	return 0;
}