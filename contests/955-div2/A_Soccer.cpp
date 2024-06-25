#include <bits/stdc++.h>
using namespace std;

int main() {
	int t;
	cin >> t;
	while(t--) {
		int a, b, x, y;
		cin >> a >> b >> x >> y;

		if(a < b && y < x) 
			cout << "NO" << '\n';
		else if(b < a && x < y)
			cout << "NO" << '\n';
		else
			cout << "YES" << '\n';
	}
	return 0;
}
