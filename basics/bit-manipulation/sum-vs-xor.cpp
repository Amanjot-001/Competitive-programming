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

	ll n;
	cin >> n;

	int zero_bits = 0;
	for(int i=0; i<64 && (1<<i)<=n; i++) {
		if((n&(1LL << i))== 0)
			zero_bits++;
	}

	cout << (1LL << zero_bits) << endl;

	return 0;
}
