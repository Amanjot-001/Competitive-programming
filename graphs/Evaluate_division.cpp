class Solution {
public:
    // construct graph and bfs simple
    struct Edge {
        string nbr;
        double wt;
        Edge(string nbr, double wt) {
            this->nbr=nbr;
            this->wt=wt;
        }
    };

    struct Graph {
        unordered_map<string, vector<Edge>> adjList;

        void addEdge(string u, string v, double wt) {
            adjList[u].emplace_back(v, wt);
            adjList[v].emplace_back(u, 1.0/wt);
        }
    };

    double bfs(unordered_map<string, vector<Edge>>& graph, string src, string dest) {
        if(graph.find(src) == graph.end() || graph.find(dest) == graph.end())
            return -1.0;

        set<string> vis;
        queue<pair<string, double>> q;
        q.push({src, 1.0});

        while(!q.empty()) {
            auto [vtx, cost] = q.front();
            q.pop();

            if(vis.find(vtx) != vis.end())
                continue;
            vis.insert(vtx);

            if(vtx == dest) {
                return cost;
            }

            for(Edge& e : graph[vtx]) {
                if(vis.find(e.nbr) != vis.end())
                    continue;
                q.push({e.nbr, cost*e.wt});
            }
        }

        return -1.0;
    }

    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        int n = equations.size();
        vector<double> ans;
        Graph graph;

        for(int i=0; i<n; i++) {
            auto x = equations[i];
            graph.addEdge(x[0], x[1], values[i]);
        }

        for(auto& q : queries) {
            ans.push_back(bfs(graph.adjList, q[0], q[1]));
        }

        return ans;
    }
};