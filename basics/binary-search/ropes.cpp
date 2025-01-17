#include <bits/stdc++.h>
using namespace std;
#define ll long long

int n, k;
vector<double> a;

bool check(double x) {
	int cnt = 0;
	for(int i=0; i<n; i++)
		cnt += (int)(a[i]/x);
	
	return cnt >= k;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> n >> k;
	for(int i=0; i<n; i++) {
		int x;
		cin >> x;
		a.emplace_back(x);
	}

	double l=0, r=1e8;

	while(abs(r-l) > 1e-6) {
		double m = l + ((r-l)/2.0);

		if(check(m)) {
			l=m;
		} else {
			r=m;
		}
	}

	cout << fixed << setprecision(6) << l << endl;
	
	return 0;
}