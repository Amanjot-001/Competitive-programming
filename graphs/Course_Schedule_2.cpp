// simple topological sort
class Solution {
public:
    vector<int> findOrder(int n, vector<vector<int>>& prerequisites) {
        vector<vector<int>> graph(n);
        vector<int> indegree(n, 0);
        vector<bool> vis(n, false);
        vector<int> top_sort;

        for(auto& it : prerequisites) {
            int u=it[1];
            int v=it[0];
            graph[u].push_back(v);
            indegree[v]++;
        }

        queue<int> q;
        for(int i=0; i<n; i++) {
            if(indegree[i] == 0)
                q.push(i);
        }

        while(!q.empty()) {
            int rem = q.front();
            q.pop();

            if(vis[rem])
                continue;
            vis[rem]=true;
            
            top_sort.push_back(rem);
            for(auto& nbr : graph[rem]) {
                if(vis[nbr])
                    continue;
                indegree[nbr]--;
                if(indegree[nbr] == 0)
                    q.push(nbr);
            }
        }

        if(top_sort.size() == n)
            return top_sort;
        return vector<int>();
    }
};