#include <bits/stdc++.h>
#include <bit>
using namespace std;
#define ll long long

const int MOD = 1e9+7;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	#ifndef ONLINE_JUDGE
		freopen("inputf.txt", "r", stdin);
		freopen("outputf.txt", "w", stdout);
	#endif

	int t;
	cin >> t;	

	while(t--) {
		int n, k, p;
		cin >> n >> k >> p;

		int ops = abs(k)/p;
		if(abs(k)%p)
			ops++;

		if(ops > n) {
			cout << -1 << endl;
		} else {
			cout << ops << endl;
		}
	}

	return 0;
}
