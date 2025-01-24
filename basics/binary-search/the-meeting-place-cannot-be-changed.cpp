#include <bits/stdc++.h>
using namespace std;
#define ll long long

int n;
vector<int> x, v;

// checking intersection empty or not
// [xi - tvi, xi + tvi]
bool check(double time) {
	double maxf = INT_MIN; // max from front
	double mine = INT_MAX; // min from end

	for(int i=0; i<n; i++) {
		double left = x[i] - v[i]*time;
		double right = x[i] + v[i]*time;

		maxf = max(maxf, left);
		mine = min(mine, right);
	}

	return mine-maxf>=0;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> n;
	x.resize(n), v.reserve(n);
	for(int i=0; i<n; i++)
		cin >> x[i];
	for(int i=0; i<n; i++)
		cin >> v[i];

	double l=0, r=1e18;
	while(abs(r-l) > 1e-6) {
		double m = l + (r-l)/2.0;
		if(check(m)) {
			r=m;	
		} else {
			l=m;
		}
	}

	cout << setprecision(15) << r << endl;
	
	return 0;
}