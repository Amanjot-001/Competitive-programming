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

class Pair {
public:
    int wsf;
    string psf;

    Pair(int wsf, string psf) {
        this->wsf = wsf;
        this->psf = psf;
    }

    bool operator>(const Pair& other) const {
        return wsf > other.wsf;
    }
};

class Graph {
public:
	vector<vector<Edge>> adjList;
	int n;
	string spath="";
	int spathwt = INT_MAX;
	string lpath="";
	int lpathwt = INT_MIN;
	string cpath="";
	int cpathwt = INT_MAX;
	string fpath = "";
	int fpathwt = INT_MIN;
    priority_queue<Pair, vector<Pair>, greater<Pair>> pq;

	Graph(int n) {
		this->n = n;
		adjList.resize(n);
	}

	void addEdge(int v1, int v2, int wt) {
		adjList[v1].emplace_back(v1, v2, wt);
		adjList[v2].emplace_back(v2, v1, wt);
	}

	void drawTree(int v, vector<bool> &vis, vector<int> &comp) {
		vis[v] = true;
		comp.push_back(v);
		for(auto e: adjList[v]) {
			if(!vis[e.nbr]) {
				drawTree(e.nbr, vis, comp);
			}
		}

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

	vector<vector<int>> comps;
	vector<bool> vis(n, false);

	for(int i=0; i<n; i++) {
		if(!vis[i]) {
			vector<int> comp;
			graph.drawTree(i, vis, comp);
			comps.push_back(comp);
		}
	}

	for(int i=0; i<comps.size(); i++) {
		for(int j=0; j<comps[i].size(); j++) {
			cout << comps[i][j] << " ";
		}
		cout << '\n';
	}
	return 0;
}
