#include <bits/stdc++.h>
using namespace std;
#define ll long long

int n;
vector<vector<int>> child;
vector<int> level, parent;
vector<vector<int>> table;
int MAX = 10;

void build() {
	table.resize(MAX+1, vector<int>(n+1, -1));
	table[0] = parent;
	for(int p=1; p<=MAX; p++) {
		for(int i=1; i<=n; i++) {
			if(table[p-1][i] != -1) {
                table[p][i] = table[p-1][table[p-1][i]];
            }
		}
	}
}

void dfs(int node, int lvl) {
	level[node] = lvl;
	for(int c : child[node]) {
		parent[c] = node;
		dfs(c, lvl+1);
	}
}

int lca(int u, int v) {
	if(level[u] > level[v])
		swap(u, v);
	int k = level[v]-level[u];
	for(int i=MAX; i>=0; i--) {
		int mask = (1<<i);
		if(k&mask)
			v = table[i][v];
	}

	if(u==v)
		return u;
	
	for(int i=MAX; i>=0; i--) {
		int up = table[i][u];
		int vp = table[i][v];
		if(up != vp) {
			u=up;
			v=vp;
		}
	}

	return parent[u];
}

void solve() {
	cin >> n;
	child.resize(n+1);
	parent.resize(n+1, -1);
	level.resize(n+1, -1);

	for(int i=1; i<=n; i++) {
		int m;
		cin >> m;
		while(m--) {
			int x;
			cin >> x;
			child[i].push_back(x);
		}
	}

	dfs(1, 1);
	build();

	int q;
	cin >> q;
	while(q--) {
		int x, y;
		cin >> x >> y;
		int ans = lca(x, y);
		cout << ans << '\n';
	}
}

signed main() {
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	int t;
	cin >> t;
	for(int i=1; i<=t; i++) {
		cout << "Case " << i << ":" << '\n';
		solve();
	}

	return 0;
}