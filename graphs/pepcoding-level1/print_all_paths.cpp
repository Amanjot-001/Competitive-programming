#include <bits/stdc++.h>
using namespace std;
using ll = long long;

class Edge {
public:
    int src;
    int nbr;
    int wt;

    Edge(int src, int nbr, int wt) {
        this->src = src;
        this->nbr = nbr;
        this->wt = wt;
    }
};

class Graph {
public:
	vector<vector<Edge>> adjList;
	int n;

	Graph(int n) {
		this->n = n;
		adjList.resize(n);
	}

	void addEdge(int v1, int v2, int wt) {
		adjList[v1].emplace_back(v1, v2, wt);
		adjList[v2].emplace_back(v2, v1, wt);
	}

	void printAllPaths(int src, int dest, vector<bool> &vis, string const &psf) {
		if(src == dest) {
			cout << psf << '\n';
			return;
		}
		
		vis[src] = true;
		for(auto e: adjList[src]) {
			if(!vis[e.nbr]) {
				printAllPaths(e.nbr, dest, vis, psf + to_string(e.nbr));
			}
		}

		vis[src] = false;
		return;
	}
};

signed main() {
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	int n, m;
	cin >> n >> m;

	Graph graph(n);
	for(int i=0; i<m; i++) {
		int v1, v2, wt;
        cin >> v1 >> v2 >> wt;
        graph.addEdge(v1, v2, wt);
	}

	int src, dest;
    cin >> src >> dest;

	vector<bool> vis(n, false);
	string psf = to_string(src);
    graph.printAllPaths(src, dest, vis, psf);

	return 0;
}
