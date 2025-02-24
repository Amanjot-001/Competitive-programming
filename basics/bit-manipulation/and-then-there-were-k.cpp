#include <bits/stdc++.h>
#include <bit>
using namespace std;
#define ll long long

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

		int msb = 1 << (31 - __builtin_clz(n));
		cout << msb - 1 << endl;
	}

	return 0;
}
