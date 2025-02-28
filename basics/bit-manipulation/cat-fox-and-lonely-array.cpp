#include <bits/stdc++.h>
#include <bit>
using namespace std;
#define ll long long

int n;
vector<int> a;

bool check(int m, int ori) {
	vector<int> frekbit(31, 0); // tracks the number of elements in the segment that have the i-th bit set.

	for(int i=0; i<m; i++) {
		int x = a[i];
		for(int j=30; j>=0; j--) {
			if(x & (1<<j))
				frekbit[j]++;
		}
	}

	int ori2 = 0;
	for(int i=0; i<31; i++) {
		if(frekbit[i])
			ori2 += (1<<i);
	}

	// cause it means some greater 2^i exists in later segments
	if(ori2 != ori)
		return false;

	for(int i=1; i<n-m+1; i++) {
		int x = a[i-1];
		for(int j=30; j>=0; j--) {
			if(x & (1<<j)) {
				frekbit[j]--;
				if(frekbit[j]==0)
					ori2 -= (1<<j);
			}
		}

		x = a[i+m-1];
		for(int j=30; j>=0; j--) {
			if(x & (1<<j)) {
				frekbit[j]++;
				if(frekbit[j] == 1)
					ori2 += (1<<j);
			}
		}

		if(ori2 != ori)
			return false;
	}

	return true;
}

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
		cin >> n;
		a.resize(n);
		int ori = 0;
		for(int& x: a) {
			cin >> x;
			ori |= x;
		}

		int l=1, r=n;
		while(l<r) {
			int m = l + ((r-l) >> 1);

			if(check(m, ori)) {
				r=m;
			} else {
				l=m+1;
			}
		}

		cout << r << endl;
	}

	return 0;
}
