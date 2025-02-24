#include <bits/stdc++.h>
using namespace std;
#define ll long long

ll findMaxSetBits(ll l, ll r) {
	if(l==r)
		return l;
	if (r == 0)
		return 0;
	ll b = 1LL << (63 - __builtin_clzll(r));

	if(b<=l)
		return findMaxSetBits(l-b, r-b) + b;
	else if(b*2-1 <= r)
		return b*2-1;

	return b-1;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	#ifndef ONLINE_JUDGE
		freopen("inputf.txt", "r", stdin);
		freopen("outputf.txt", "w", stdout);
	#endif

	int n;
	cin >> n;

	while(n--) {
		ll l, r;
		cin >> l >> r;

		cout << findMaxSetBits(l, r) << endl;
	}

	return 0;
}
