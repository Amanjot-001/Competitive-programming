#include <bits/stdc++.h>
using namespace std;

const int N = 1e6;
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	vector<int> d(N, 0);

	for(int i=1; i<N; i++) {
		for(int j=i; j<N; j+=i) {
			d[j] += i;
		}
	}

	int t;
	cin >> t;
	while(t--) {
		int n;
		cin >> n;

		cout << (d[n] - n) << endl;
	}

	return 0;
}
