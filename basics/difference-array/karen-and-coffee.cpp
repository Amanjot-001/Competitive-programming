#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int n, k, q;
	cin >> n >> k >> q;
	const int max_t = 200000;

	vector<int> temp(max_t + 1, 0);
	for(int i=0;i<n; i++) {
		int l, r;
		cin >> l >> r;
		temp[l]++;
		temp[r+1]--;
	}

	for(int i=1; i<=max_t; i++) {
		temp[i] += temp[i-1];
	}

	for(int i=0; i<=max_t; i++) {
		temp[i] = temp[i]>=k ? 1 : 0;
	}

	for(int i=1; i<=max_t; i++) {
		temp[i] += temp[i-1];
	}

	while(q--) {
		int a, b;
		cin >> a >> b;

		cout << (temp[b]-temp[a-1]) << endl;
	}

	return 0;
}