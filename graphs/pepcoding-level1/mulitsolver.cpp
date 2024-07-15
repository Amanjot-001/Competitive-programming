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

	void multisolver(int src, int dest, vector<bool> &vis, int criteria, int k, string const &psf, int wsf) {
		if(src == dest) {
			if(wsf < spathwt) {
				spathwt = wsf;
				spath = psf;
			}
			if(wsf > lpathwt) {
				lpathwt = wsf;
				lpath = psf;
			}
			if(wsf > criteria && wsf < cpathwt) {
				cpathwt = wsf;
				cpath = psf;
            }
			if(wsf < criteria && wsf > fpathwt) {
				fpathwt = wsf;
				fpath = psf;
			}
			if(pq.size() < k) {
                pq.push(Pair(wsf, psf));
            } else if (wsf > pq.top().wsf) {
                pq.pop();
                pq.push(Pair(wsf, psf));
            }
			return;
		}
		
		vis[src] = true;
		for(auto e: adjList[src]) {
			if(!vis[e.nbr]) {
				multisolver(e.nbr, dest, vis, criteria, k, psf + to_string(e.nbr), wsf+e.wt);
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

	int criteria, k;
	cin >> criteria >> k;

	vector<bool> vis(n, false);
	string psf = to_string(src);

    graph.multisolver(src, dest, vis, criteria, k, psf, 0);
	cout << "shortest path:" << graph.spath << "@" << graph.spathwt << '\n';
	cout << "longest path:" << graph.lpath << "@" << graph.lpathwt << '\n';
	cout << "ceil path:" << graph.cpath << "@" << graph.cpathwt << '\n';
	cout << "floor path:" << graph.fpath << "@" << graph.fpathwt << '\n';
	cout << k << "th largest path = " << graph.pq.top().psf << "@" << graph.pq.top().wsf << "\n";

	return 0;
}
