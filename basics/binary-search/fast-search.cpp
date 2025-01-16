#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int n;
	cin >> n;
	vector<int> a(n);
	for(int i=0; i<n; i++)
		cin >> a[i];

	int k;
	cin >> k;
	
	sort(a.begin(), a.end());

	while(k--) {
		int lo, hi;
		cin >> lo >> hi;

		auto l = lower_bound(a.begin(), a.end(), lo);
		auto r = upper_bound(a.begin(), a.end(), hi);

		cout << (r-l) << endl;
	}

	return 0;
}