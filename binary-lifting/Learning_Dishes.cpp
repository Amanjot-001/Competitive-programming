#include <bits/stdc++.h>
using namespace std;
#define ll long long

int n;
vector<int> value, parent;
vector<vector<int>> child;
vector<pair<int, int>> dp;

void dfs(int node, int max, int cnt) {
	if(value[node] > max) {
		max = value[node];
		cnt++;
	}

	dp[node] = {max, cnt};
	for(int c : child[node]) {
		dfs(c, max, cnt);
	}
}

int cal(int u, int w) {
	int curr = u;
	while(true) {
		int p = parent[curr];
		curr = p;	
		if(dp[p].first <= w)
			break;
	}

	return dp[u].second - dp[curr].second;
}

void solve() {
	cin >> n;
	value.resize(n+1);
	parent.resize(n+1);
	child.resize(n+1);

	for(int i=1; i<=n; i++)
		cin >> value[i];
	for(int i=2; i<=n; i++) {
		cin >> parent[i];
		child[parent[i]].push_back(i);
	}

	dp.resize(n+1);
	dp[0]={0, 0};
	dfs(1, 0, 0);

	int pr = 0;
	int q;
	cin >> q;
	while(q--) {
		int u, w;
		cin >> u >> w;
		u = pr ^ u;
		w = pr ^ w;
		pr = cal(u, w);
		cout << pr << '\n';
	}
}

int32_t main() {
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	int t;
	cin >> t;
	while(t--) {
		solve();
	}

	return 0;
}