#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main() {
	int n;
	cin >> n;
	vector<int> a(n);
	ll s=0;
	for(int i=0; i<n; i++) {
		cin >> a[i];
		s += a[i];
	}

	if(s!=0) {
		puts("YES");
		puts("1");
		cout << 1 << " " << n << endl;
	} else {
		ll curr = 0;
		for(int i=1; i<=n; i++) {
			curr += a[i-1];
			if(curr != 0) {
				puts("YES");
				puts("2");
				cout << 1 << " " << i << endl;
				cout << i+1 << " " << n << endl;
				return 0;
			}
		}

		puts("NO");
	}

    return 0;
}