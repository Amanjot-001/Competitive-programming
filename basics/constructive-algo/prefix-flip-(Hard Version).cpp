#include <bits/stdc++.h>
using namespace std;
#define ll long long

int t, n;
string a, b;

int main() {
    ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> t;

	while(t--) {
		cin >> n >> a >> b;

		// first main a -> 0000's then making 00000's -> b (by going in reverse order)
		vector<int> ops1, ops2;
		a += '0', b += '0';
		for(int i=1; i<=n; i++) {
			if(a[i] != a[i-1]) ops1.push_back(i);
			if(b[i] != b[i-1]) ops2.push_back(i);
		}
		
		ops1.insert(ops1.end(), ops2.rbegin(), ops2.rend());
		cout << ops1.size() << " ";
		for(int x: ops1)
			cout << x << " ";
		cout << endl;
	}

	return 0;
}
