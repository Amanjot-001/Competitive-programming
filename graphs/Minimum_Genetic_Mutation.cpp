// https://leetcode.com/problems/minimum-genetic-mutation/?envType=study-plan-v2&envId=top-interview-150
// make graph carefully and push to child only if exact 1 diff char
// after this simple bfs
// set for visited as strings so can't use array index

class Solution {
public:
    unordered_map<string, vector<string>> graph;
    bool req=false;
    int n=0;

    bool isNode(string start, string end) {
        int diff=0;
        for(int i=0; i<8; i++) {
            if(start[i] != end[i])
                diff++;
            if(diff>1)
                return false;
        }
        return diff==1;
    }

    void build(string start, string end, vector<string>& bank) {
        bank.push_back(start);
        for(int i=0; i<n+1; i++) {
            if(bank[i] == end)
                req=true;
            for(int j=i+1; j<n+1; j++){
                if(isNode(bank[i],bank[j])){
                    graph[bank[i]].push_back(bank[j]);
                    graph[bank[j]].push_back(bank[i]);
                }
            }
        }
    }

    int minMutation(string startGene, string endGene, vector<string>& bank) {
        n=bank.size();
        build(startGene, endGene, bank);
        if(!req)
            return -1;

        unordered_set<string> vis;
        queue<pair<string, int>> q;
        q.push({startGene, 0});

        while(!q.empty()) {
            auto [rem, moves] = q.front();
            q.pop();
            
            if(rem == endGene)
                return moves;
            if(vis.find(rem) != vis.end())
                continue;
            vis.insert(rem);

            for(auto& nbr : graph[rem]) {
                if(vis.find(nbr) != vis.end())
                    continue;
                q.push({nbr, moves+1});
            }
        }

        return -1;
    }
};