#include <bits/stdc++.h>
#include <bit>
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

	int n;
	cin >> n;
	vector<int> a(n);
	vector<int> frekbit(20, 0);

	for(int i=0; i<n; i++) {
		cin >> a[i];
		for(int j=0; j<20; j++) {
			if(a[i] & (1<<j))
				frekbit[j]++;
		}
	}

	vector<int> final(n, 0);
	for(int i=0; i<20; i++) {
		for(int j=n-frekbit[i]; j<n; j++) {
			final[j] |= (1<<i);
		}
	}
	
	ll sum = 0;
	for(int i=0; i<n; i++)
		sum += 1LL * final[i] * final[i];

	cout << sum << endl;

	return 0;
}
