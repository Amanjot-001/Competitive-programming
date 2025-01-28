#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int n;
	cin >> n;
	vector<int> a(n);
	for(int i=0; i<n; i++) {
		cin >> a[i];
	}

	int i=0, j=n-1;
	ll sa=0, sc=0; // sum of segment a and c
	ll ans = 0;

	while(i<=j) {
		if (sa < sc) {
			sa += a[i];
			i++;
		} else if (sa > sc) {
			sc += a[j];
			j--;
		} else { // sa == sc
			ans = sa; 
			sa += a[i];
			i++;
		}
	}

	if(sa==sc)
		ans = sa;

	cout << ans << endl;

	return 0;
}