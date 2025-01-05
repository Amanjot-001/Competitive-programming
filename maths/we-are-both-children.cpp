#include <bits/stdc++.h>
using namespace std;

const int N = 1e6;
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int t;
	cin >> t;
	while(t--) {
		int n;
		cin >> n;

		vector<int> cnt(n+1, 0), d(n+1, 0);

		for(int i=0; i<n; i++) {
			int x;
			cin >> x;

			if(x <= n)
				cnt[x]++;
		}

		for(int i=1; i<=n; i++) {
			for(int j=i; j<=n; j+=i) {
				d[j] += cnt[i];
			}
		}

		cout << (*max_element(d.begin(), d.end())) << endl;
	}

	return 0;
}
