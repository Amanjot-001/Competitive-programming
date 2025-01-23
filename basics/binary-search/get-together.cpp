#include <bits/stdc++.h>
using namespace std;
#define ll long long

int n;
vector<double> x, v;

bool check(double time) {
	double maxf = INT_MIN, mine = INT_MAX;
	for(int i=0; i<n; i++) {
		double l = x[i] - v[i]*time;
		double r = x[i] + v[i]*time;

		maxf = max(maxf, l);
		mine = min(mine, r);
	}

	return mine-maxf>=0;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> n;
	x.resize(n), v.resize(n);
	for(int i=0; i<n; i++)
		cin >> x[i] >> v[i];

	double l=0.0, r=2*1e9;

	while(abs(r-l) > 1e-6) {
		double m = l + ((r-l)/2.0);
		if(check(m)) {
			r=m;
		} else {
			l=m;
		}
	}

	cout << setprecision(15) << r << endl;

	return 0;
}