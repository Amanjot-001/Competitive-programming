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

	int i=0, j=0;
	ll ans = 0;
	while(i<n && j<m) {
		if(a[i] == b[j]) {
			ll cntA = 1;
			while(i+1<n && a[i] == a[i+1]) {
				cntA++;
				i++;
			}

			ll cntB = 1;
			while(j+1<m && b[j] == b[j+1]) {
				cntB++;
				j++;
			}

			ans += (cntA*cntB);
			i++;
			j++;
		} else if(a[i] < b[j]) {
			i++;
		} else {
			j++;
		}
	}

	cout << ans << endl;

	return 0;
}