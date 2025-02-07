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

		vector<int> ops;

		// flip prefix then flip 1 then again flip prefix
		// by this only desired bit will change
		for(int i=0; i<n; i++) {
			if(a[i] != b[i]) {
				if(i>0) ops.push_back(i+1);
				ops.push_back(1);
				if(i>0)	ops.push_back(i+1);
			}
		}

		cout << ops.size() << " ";
		for(int x: ops)
			cout << x << " ";
		cout << endl;
	}

	return 0;
}
