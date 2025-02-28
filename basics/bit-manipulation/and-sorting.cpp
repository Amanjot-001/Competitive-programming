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
		cin >> n;
		vector<int> p(n);
		bitset<200001> b;

		for(int i=0; i<n; i++) {
			cin >> p[i];
			if(p[i] != i)
				b[i] = 1;
		}

		int ans = 0xFFFFFFFF;
		for(int i=n-1; i>=0; i--) {
			if(b[i]) {
				ans = ans&i;
			}
		}

		cout << ans << endl;

	}

	return 0;
}
