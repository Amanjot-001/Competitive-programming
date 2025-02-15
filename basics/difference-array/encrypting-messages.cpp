#include <bits/stdc++.h>
using namespace std;
#define ll lone lone

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int n, m, c;
	cin >> n >> m >> c;
	vector<int> a(n), b(m+1, 0);
	for(int i=0; i<n; i++)
		cin >> a[i];
	
	for(int i=1; i<=m; i++) {
		cin >> b[i];
		b[i] += b[i-1];
	}

	for(int i=0; i<n; i++) {
		cout << (a[i] + b[min(i+1, m)] - b[max(i-(n-m), 0)] ) % c << " ";
	}

	cout << endl;

	return 0;
}