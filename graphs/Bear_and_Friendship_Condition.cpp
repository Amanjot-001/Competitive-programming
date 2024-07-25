#include <bits/stdc++.h>
using namespace std;
#define ll long long

class Edge {
public:
	int src;
	int nbr;

	Edge(int src, int nbr) {
		this->src=src;
		this->nbr=nbr;
	}
};

int n, m;
vector<vector<Edge>> graph;
vector<int> parent, rankk;
vector<bool> res;

int find(int x) {
	if(parent[x] == x)
		return x;
	int temp = find(parent[x]);
	parent[x]=temp;
	return temp;
}

void unionSets(int x, int y) {
	int lx = find(x);
	int ly = find(y);

	if(lx != ly) {
		if(rankk[lx] < rankk[ly])
			parent[lx] = ly;
		else if(rankk[lx] > rankk[ly])
			parent[ly] = lx;
		else {
			if(x > y) {
				parent[ly] = lx;
				rankk[lx]++;
			} else {
				parent[lx] = ly;
				rankk[ly]++;
			}
		}
	} else {
		res[x]=true;
		res[y]=true;
		res[lx]=true;
	}
}

signed main() {
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	cin >> n >> m;

	parent.resize(n);
	rankk.resize(n);
	res.resize(n, true);

	for(int i=0; i<n; i++) {
		parent[i]=i;
		rankk[i]=1;
	}

	graph.resize(n);
	for(int i=0; i<m; i++) {
		int x, y;
		cin >> x >> y;
		x--, y--;

		res[x]=false;
		res[y]=false;
		unionSets(x, y);
	}

	bool isValid = true;
	for(int i=0; i<n; i++) {
		if(!res[i]) {
			isValid=false;
			break;
		}
	}

	for(auto x : res)
		cout << x << " ";

	cout << (isValid ? "YES" : "NO") << '\n';
	
	return 0;
}