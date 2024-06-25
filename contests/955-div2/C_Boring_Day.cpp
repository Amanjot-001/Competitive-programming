#include <bits/stdc++.h>
using namespace std;

int main() {
	int t;
	cin >> t;
	while(t--) {
		int n, l, r;
		cin >> n >> l >> r;

		vector<int> a(n);
        for(int i = 0; i < n; i++) {
            cin >> a[i];
        }

		int ans = 0;
        long long sum = 0;
        int start = 0;

        for(int i = 0; i < n; i++) {
            sum += a[i];
            while(sum > r && start <= i) {
                sum -= a[start];
                start++;
            }
            if(sum >= l && sum <= r) {
                ans++;
                sum = 0;
                start = i + 1;
            }
        }

        cout << ans << '\n';
	}
	return 0;
}
