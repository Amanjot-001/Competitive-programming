#include <bits/stdc++.h>
using namespace std;

bool canGetDrunk(int m, vector<pair<string, string>>& prerequisites) {
    unordered_map<string, vector<string>> adj;
    unordered_map<string, int> inDegree;

    for (auto& pre : prerequisites) {
        string a = pre.first;
        string b = pre.second;
        adj[a].push_back(b);
        inDegree[b]++;
        inDegree[a] += 0;
    }

    queue<string> q;
    for (auto& node : inDegree) {
        if (node.second == 0) {
            q.push(node.first);
        }
    }

    int count = 0;
    while (!q.empty()) {
        string curr = q.front();
        q.pop();
        count++;

        for (auto& neighbor : adj[curr]) {
            inDegree[neighbor]--;
            if (inDegree[neighbor] == 0) {
                q.push(neighbor);
            }
        }
    }

    return count == inDegree.size();
}

int main() {
    int T;
    cin >> T;

    for (int t = 1; t <= T; t++) {
        int m;
        cin >> m;

        vector<pair<string, string>> prerequisites(m);
        for (int i = 0; i < m; i++) {
            string a, b;
            cin >> a >> b;
            prerequisites[i] = {a, b};
        }

        if (canGetDrunk(m, prerequisites)) {
            cout << "Case " << t << ": Yes" << endl;
        } else {
            cout << "Case " << t << ": No" << endl;
        }
    }

    return 0;
}
