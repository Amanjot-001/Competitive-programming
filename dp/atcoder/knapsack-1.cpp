#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int n, w;
	cin >> n >> w;
	vector<ll> weight(n), value(n);

	for(int i=0; i<n; i++) {
		cin >> weight[i];
		cin >> value[i];
	}

	vector<ll> dp(w+1, 0);

	for(int i=0; i<n; i++) {
		for(int j=w; j>=weight[i]; j--) {
			dp[j] = max(dp[j], dp[j-weight[i]] + value[i]);
		}
	}

	cout << dp[w] << '\n';
	
	return 0;
}