#include <bits/stdc++.h>
using namespace std;

int main() {
	int t;
	cin >> t;
	while(t--) {
		int n, m;
		cin >> n >> m;
		string s;
		cin >> s;

		vector<int> v(7, 0);

		for(auto it: s) {
			v[it - 'A']++;
		}

		int ans = 0;

		for(auto it: v) {
			if(it < m)
				ans += m - it;
		}

		cout << ans << endl;
	}
	return 0;
}
