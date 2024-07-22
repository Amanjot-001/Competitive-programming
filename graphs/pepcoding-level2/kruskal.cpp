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

vector<int> parent;
vector<int> rankk;

int find(int x) {
	if(parent[x] == x)
		return x;
	int temp = find(parent[x]);
	parent[x] = temp;
	return temp;
}

bool unionSets(int x, int y) {
	int lx = find(x);
	int ly = find(y);
	if(lx != ly) {
		if(rankk[lx] > rankk[ly])
			parent[ly] = lx;
		else if(rankk[lx] < rankk[ly])
			parent[lx] = ly;
		else {
			parent[lx] = ly;
			rankk[ly]++;
		}
		return true;
	}
	return false;
}

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

	parent.resize(n);
	rankk.resize(n, 1);

	for(int i=0; i<n; i++)
		parent[i] = i;

	vector<tuple<int, int, int>> edges;
    for (int i = 0; i < n; i++) {
        for (Edge e : graph.adjList[i]) {
            if (i < e.nbr) {
                edges.emplace_back(e.wt, e.src, e.nbr);
            }
        }
    }

    sort(edges.begin(), edges.end());

	int ans = 0;
    for (auto& [wt, v1, v2] : edges) {
        if (unionSets(v1, v2)) {
            ans += wt;
        }
    }

    cout << ans << endl;

	return 0;
}