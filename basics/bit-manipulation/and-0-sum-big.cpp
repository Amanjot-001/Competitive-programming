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
		int n, k;
		cin >> n >> k;

		ll ans = 1;
		for(int i=0; i<k; i++)
			ans = (ans*n)%MOD;

		cout << ans << endl;
	}

	return 0;
}
