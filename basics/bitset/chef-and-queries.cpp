#include <bits/stdc++.h>
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

	const ll limit = 1LL << 32;
	bitset<limit> bb;
	ll sum = 0;

	ll q, s, a, b;
	cin >> q >> s >> a >> b;

	while(q--) {
		int num = s/2;
		if(s&1) {
			if(!bb[num]) {
				bb[num] = 1;
				sum += num;
			}
		} else {
			if(bb[num]) {
				bb[num] = 0;sum -= num;
			}
		}

		s = (1LL*a*s + b) % limit;
	}

	cout << sum << endl;

	return 0;
}
