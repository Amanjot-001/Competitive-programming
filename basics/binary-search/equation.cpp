#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define lld long double

long double c;

bool check(double m) {
    return (m*m + sqrt(m)) <= c;
}

int32_t main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> c;

	long double l=0.0, r=c;

	while(abs(r-l) > 1e-6) {
		long double m = (l+r)/2;

		if(check(m)) {
			l=m;
		} else {
			r=m;
		}
	}

	cout << fixed << setprecision(6) << l << endl;

    return 0;
}