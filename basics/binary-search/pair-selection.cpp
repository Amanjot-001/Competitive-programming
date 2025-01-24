#include <bits/stdc++.h>
using namespace std;
#define ll long long

int n, k;
vector<vector<int>> a;

bool check(double x) {
	vector<double> m(n, 0);
	for(int i=0; i<n; i++) {
		m[i] = (a[i][0] - a[i][1]*x);
	}

	sort(m.rbegin(), m.rend());
	double sum=0;

	for(int i=0; i<k; i++)
		sum += m[i];

	return sum >= 0;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> n >> k;
	a.resize(n, vector<int>(2));
	for(int i=0; i<n; i++)
		cin >> a[i][0] >> a[i][1];

	double l=0, r=1e5;
	while(abs(r-l) > 1e-7) {
		double m = l + ((r-l)/2.0);
		if(check(m)) {
			l=m;
		} else {
			r=m;
		}
	}

	cout << setprecision(15) << l << endl;

	return 0;
}