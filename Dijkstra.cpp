#include <bits/stdc++.h>
using namespace std;
#define ll long long

class Edge {
public:
	int src;
	int nbr;
	int wt;

	Edge(int src, int nbr, int wt) {
		this->src=src;
		this->nbr=nbr;
		this->wt=wt;
	}
};

class Graph {
public:
	vector<vector<Edge>> adjList;

	Graph(int n) {
		adjList.resize(n);
	}

	void addEdge(int u, int v, int wt) {
		adjList[u].emplace_back(u, v, wt);
		adjList[v].emplace_back(v, u, wt);
	}
};

int n, m;
vector<bool> vis;
vector<int> parent, dist;

signed main() {
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	cin >> n >> m;

	Graph graph(n);
	vis.resize(n ,false);
	parent.resize(n, -1);
	dist.resize(n, INT_MAX);

	for(int i=0; i<m; i++) {
		int u, v, wt;
		cin >> u >> v >> wt;

		graph.addEdge(--u, --v, wt);
	}

	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
	pq.push({0, 0});
	dist[0]=0;

	while(!pq.empty()) {
		auto [wt, vtx] = pq.top();
		pq.pop();

		if(vis[vtx])
			continue;
		vis[vtx]=true;

		if(vtx == n-1) {
			vector<int> path;
			
			for(int i=vtx; i != -1; i=parent[i])
				path.push_back(i);

			for(int i=path.size()-1; i>=0; i--)
				cout << path[i]+1 << " ";
			cout << '\n';

			return 0;
		}

		for(Edge e : graph.adjList[vtx]) {
			if(!vis[e.nbr] && wt + e.wt < dist[e.nbr]) {
				dist[e.nbr] = wt + e.wt;
				parent[e.nbr] = vtx;
				pq.push({e.wt + wt, e.nbr});
			}
		}
	}

	cout << -1 << '\n';
	
	return 0;
}