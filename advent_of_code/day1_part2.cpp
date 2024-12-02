#include <bits/stdc++.h>
using namespace std;
#define ll long long

const int N = 1000;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	vector<ll> v1;
	unordered_map<ll, int> freq;

	for (int i = 0; i < N; i++) {
		ll temp1, temp2;
		cin >> temp1 >> temp2;
		v1.push_back(temp1);
		freq[temp2]++;
	}

	ll ans = 0;
	int n = v1.size();
	for (int i = 0; i < n; i++) {
		if(freq.find(v1[i]) != freq.end()) {
			ans += v1[i] * freq[v1[i]];
		}
	}

	cout << ans << endl;
	return 0;
}
