#include <bits/stdc++.h>
using namespace std;
#define ll long long

int n, k;
vector<int> a;

bool check(ll maxsum) {
	int sub_cnt = 0;
	ll curr = 0;
	for(auto x: a) {
		if(x > maxsum)
			return false;
		
		if(curr + x > maxsum) {
			sub_cnt++;
			curr=0;
		}

		curr += x;
	}

	if(curr>0)
		sub_cnt++;

	return sub_cnt <= k;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> n >> k;
	a.resize(n);
	for(int i=0; i<n; i++)
		cin >> a[i];

	ll l = *max_element(a.begin(), a.end());
	ll r = accumulate(a.begin(), a.end(), 0LL);

	while(l<r) {
		ll m = l + ((r-l) >> 1);
		if(check(m)) {
			r=m;
		} else {
			l=m+1;
		}
	}

	cout << r << endl;

	return 0;
}