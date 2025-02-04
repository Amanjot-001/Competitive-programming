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
	for(int i=0; i<n; i++)
		cin >> a[i];

	sort(a.begin(), a.end());

	ll x = 1;
	for(int i=0; i<n; i++) {
		if(a[i] > x) {
			cout << x << endl;
			return 0;
		}
		x += a[i];
	}

	cout << x << endl;

	return 0;
}