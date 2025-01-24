#include <bits/stdc++.h>
using namespace std;
#define ll long long

int n;
vector<int> a;
ll sum=0;

bool check(ll x) {
	return (sum+n-2)/(n-1) <= x; // ceil(sub(ai)/(n-1)) <= x
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> n;
	a.resize(n);

	for(int i=0; i<n; i++) {
		cin >> a[i];
		sum += a[i];
	}
	
	ll l=*max_element(a.begin(), a.end()), r=sum;

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