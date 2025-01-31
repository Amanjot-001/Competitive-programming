#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n;
	cin >> n;
	
	vector<int> dp;
	for(int i=0; i<n; i++) {
		int x;
		cin >> x;

		int l = upper_bound(dp.begin(), dp.end(), x) - dp.begin();

		if(l == dp.size()) // not found
			dp.push_back(x);
		else
			dp[l] = x;
	}

	cout << dp.size() << endl;

    return 0;
}