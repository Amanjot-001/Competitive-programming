#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	freopen("outofplace.in", "r", stdin);
	freopen("outofplace.out", "w", stdout);

	int n;
	cin >> n;
	vector<int> cows(n), sorted_cows(n);
	for(int i=0; i<n; i++)
		cin >> cows[i];

	sorted_cows = cows;
	sort(sorted_cows.begin(), sorted_cows.end());

	int ans = 0;
	for(int i=0; i<n; i++)
		if(cows[i] != sorted_cows[i])
			ans++;

	cout << ans-1 << endl;

	return 0;
}