#include <bits/stdc++.h>
using namespace std;
#define ll long long

int n, k;
vector<int> a;

bool check(int gap) {
	int curr = 0;
	int cnt = 1;

	for(int i=1; i<n; i++) {
		curr += a[i] - a[i-1];
		if(curr >= gap) {
			cnt++;
			curr=0;
		}
	}

	return cnt >= k;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> n >> k;
	a.resize(n);
	for(int i=0; i<n; i++)
		cin >> a[i];

	int l = 1;
	int r = a[n-1] - a[0];

	while(l+1<r) {
		int m = l + ((r-l) >> 1);
		if(check(m)) {
			l=m;
		} else {
			r=m-1;
		}
	}

	cout << (check(r) ? r : l) << endl;

	return 0;
}