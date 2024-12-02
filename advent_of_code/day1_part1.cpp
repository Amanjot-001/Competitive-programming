#include <bits/stdc++.h>
using namespace std;
#define ll long long

const int N = 1000;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	vector<ll> v1, v2;

	for (int i = 0; i < N; i++) {
		ll temp1, temp2;
		cin >> temp1 >> temp2;
		v1.push_back(temp1);
		v2.push_back(temp2);
	}

	sort(v1.begin(), v1.end());
	sort(v2.begin(), v2.end());

	ll ans = 0;
	int n = v1.size();
	for (int i = 0; i < n; i++) {
		ans += abs(v1[i] - v2[i]);
	}

	cout << ans << endl;
	return 0;
}
