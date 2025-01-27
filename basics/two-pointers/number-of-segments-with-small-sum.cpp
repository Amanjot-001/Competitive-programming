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
	ll res = 0;

	for(int i=0, j=0; j<n; j++) {
		sum+=a[j];
		while(sum>s) {
			sum-=a[i];
			i++;
		}

		res += j-i+1;
	}	

	cout << res << endl;

	return 0;
}