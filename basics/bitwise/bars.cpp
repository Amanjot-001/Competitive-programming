#include <bits/stdc++.h>
using namespace std;

int main() {
	int t;
	cin >> t;

	while (t--) {
		int p, n;
		cin >> p >> n;

		vector<int> a(n);
		for(int i=0; i<n; i++)
			cin >> a[i];

		bool found = false;

		for(int mask=0; mask<(1<<n); mask++) {
			int len = 0;
			for(int i=0; i<n; i++) {
				if(mask&(1<<i))
					len += a[i];
			}

			if(len == p) {
				found = true;
				break;
			}
		}

		if(found)
			puts("YES");
		else
			puts("NO");
	}
	
	return 0;
}