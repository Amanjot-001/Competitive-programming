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
		int n;
		string s;
		cin >> n >> s;

		ll dash=0, underscore=0;
		for(char c: s) {
			if(c == '-')
				dash++;
			else
				underscore++;
		}

		ll ans = 0;
		if(dash&1) {
			ans = (dash/2+1) * underscore * (dash/2);
		} else {
			ans = dash/2 * underscore * dash/2;
		}

		cout << ans << endl;
	}

	return 0;
}
