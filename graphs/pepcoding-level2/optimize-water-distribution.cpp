// prims-mst
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

	bool operator<(const Edge& other) const {
        return wt > other.wt;
    }
};

class Graph {
public:
	vector<vector<Edge>> adjList;
	int n;

	Graph(int n) {
		this->n=n;
		adjList.resize(n);
	}

	void addEdge(int v1, int v2, int wt) {
		adjList[v1].emplace_back(v1, v2, wt);
		adjList[v2].emplace_back(v2, v1, wt);
	}
};

int minCostToSupplyWater(int n, int m, vector<int>& wells, vector<vector<int>>& pipes) {
	Graph graph(n+1);
	for(int i=0; i<m; i++) {
		int u = pipes[i][0];
		int v = pipes[i][1];
		int wt = pipes[i][2];
		graph.addEdge(u, v, wt);
	}

	for(int i=1; i<=n; i++) {
		graph.addEdge(0, i, wells[i-1]);
	}

	int ans=0;
	vector<bool> vis(n+1, false);
	priority_queue<Edge> pq;
	pq.emplace(0, 0, 0);

	while(!pq.empty()) {
		Edge rem = pq.top();
		pq.pop();

		if(vis[rem.nbr])
			continue;
		
		ans += rem.wt;
		vis[rem.nbr] =true;

		for(auto &edge : graph.adjList[rem.nbr]) {
			if(vis[edge.nbr])
				pq.emplace(edge.src, edge.nbr, edge.wt);
		}
	}

	return ans;
}

signed main() {
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	int n, m;
	cin >> n >> m;

	vector<int> wells(n);
    for (int i = 0; i < n; ++i) 
        cin >> wells[i];

    vector<vector<int>> pipes(m, vector<int>(3));
    for (int i = 0; i < m; ++i)
        cin >> pipes[i][0] >> pipes[i][1] >> pipes[i][2];

    cout << minCostToSupplyWater(n, m, wells, pipes) << endl;	

	return 0;
}