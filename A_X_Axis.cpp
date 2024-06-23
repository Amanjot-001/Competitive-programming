#include <bits/stdc++.h>
using namespace std;

int main() {
	int t;
	cin >> t;
	while(t--) {
		int a, b, c;
		cin >> a >> b >> c;
		vector<int> v{a, b, c};
		sort(v.begin(), v.end());
		int x = 0;

		if(a==b)
			x = a;
		else if(b == c)
			x = b;
		else if(a == c)
			x = c;
		else
			x = v[1];

		cout << (abs(a-x) + abs(b-x) + abs(c-x)) << endl;
	}
	return 0;
}
