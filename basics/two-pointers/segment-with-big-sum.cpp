#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int n;
	ll s;
	cin >> n >> s;
	vector<int> a(n);
	for(int i=0; i<n; i++)
		cin >> a[i];

	ll sum = 0;
	int res = 1e6;

	for(int j=0, i=0; j<n; j++) {
		sum+=a[j];
		while(sum-a[i]>=s) {
			sum -= a[i];
			i++;
		}

		if(sum>=s)
		res = min(res, j-i+1);
	}

	cout << (res==1e6 ? -1 : res) << endl;

	return 0;
}