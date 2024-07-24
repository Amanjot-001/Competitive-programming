#include <bits/stdc++.h>
using namespace std;
#define ll long long

int n, m;
int ans=0;

class Edge {
public:
	int src;
	int nbr;

	Edge(int src, int nbr) {
		this->src = src;
		this->nbr = nbr;
	}
};

void bfs(vector<vector<Edge>>& graph, vector<int>& cats) {
	vector<bool> vis(n, false);
	queue<pair<int, int>> q;
	q.push({0, cats[0]});

	while(!q.empty()) {
		pair<int, int> rem = q.front();
		q.pop();

		if(vis[rem.first])
			continue;
		vis[rem.first]=true;

		bool isLeaf = true;
		for(Edge e : graph[rem.first]) {
			if(!vis[e.nbr])
				isLeaf=false;
		}

		if(isLeaf) {
			ans++;
			continue;
		}

		for(Edge e : graph[rem.first]) {
			if(!vis[e.nbr]) {
				int currCats = rem.second + cats[e.nbr];
				if(currCats <= m) {
					if(cats[e.nbr])
						q.push({e.nbr, currCats});
					else
						q.push({e.nbr, 0});
				}
			}
		}
	}
}

signed main() {
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	cin >> n >> m;

	vector<int> cats(n);

	for(int i=0; i<n; i++)
		cin >> cats[i];

	vector<vector<Edge>> graph(n);
	for(int i=0; i<n-1; i++) {
		int x, y;
		cin >> x >> y;
		x--, y--;
	
		graph[x].push_back(Edge(x, y));
		graph[y].push_back({y, x});
	}

	bfs(graph, cats);

	cout << ans << '\n';

	return 0;
}