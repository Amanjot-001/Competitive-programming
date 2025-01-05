#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	freopen("div7.in", "r", stdin);
	freopen("div7.out", "w", stdout);

	int n;
	cin >> n;
	vector<int> a(n);

	for(int i=0; i<n; i++)
		cin >> a[i];
	
	vector<int> p(n+1, 0);
	for(int i=1; i<=n; i++)
		p[i] = (p[i-1] + a[i-1]) % 7;

	vector<int> lastFound(7, -1);
	int ans = 0;

	for(int i=1; i<p.size(); i++) {
		if(lastFound[p[i]] == -1)
			lastFound[p[i]] = i;
		else
			ans = max(ans, i - lastFound[p[i]]);
	}

	cout << ans << endl;

	return 0;
}
