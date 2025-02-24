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

	int t;
	cin >> t;	

	while(t--) {
		int n;
		cin >> n;
		int a, b;

		bool found = false;
		for(a=1; a<=n; a++) {
			b = a^n;
			if(a<=b && b<=n) {
				found = true;
				break;
			}
		}

		if(found)
			cout << a << " " << b << endl;
		else
			cout << -1 << endl;
	}

	return 0;
}
