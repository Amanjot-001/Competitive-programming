#include <bits/stdc++.h>
using namespace std;
#define ll long long

int computeXor(int n) {
	if (n % 4 == 0)
		return n;

	if (n % 4 == 1)
		return 1;

	if (n % 4 == 2)
		return n + 1;

  	return 0;
}

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
		int a, b;
		cin >> a >> b;

		int xorr = computeXor(a-1);
		if(xorr == b)
			cout << a << endl;
		else {
			if((xorr ^ b) != a)
				cout << a+1 << endl;
			else
				cout << a+2 << endl;
		}
	}

	return 0;
}
