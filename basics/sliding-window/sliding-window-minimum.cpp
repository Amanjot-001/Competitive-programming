#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	#ifndef ONLINE_JUDGE
		freopen("inputf.txt", "r", stdin);
		freopen("outputf.txt", "w", stdout);
	#endif

	int n, k;
	cin >> n >> k;
	int x, a, b, c;
	cin >> x >> a >> b >> c;
	vector<int> v(n);
	v[0] = x;
	for(int i=1; i<n; i++)
		v[i] = (1LL*a*v[i-1] + b) % c;
	

	deque<int> dq;
	ll ans = 0;

	for(int i=0; i<n; i++) {
		if(!dq.empty() && dq.front() < i-k+1)
			dq.pop_front();

		while(!dq.empty() && v[i] <= v[dq.back()])
			dq.pop_back();

		dq.push_back(i);

		if(i>=k-1)
			ans ^= v[dq.front()];
	}

	cout << ans << endl;

	return 0;
}
