// https://leetcode.com/problems/snakes-and-ladders/?envType=study-plan-v2&envId=top-interview-150
// made mapping of cell numbers to (i,j) for checking board
// simple bfs with conditions check
// stored dist instead of making a visited arr
class Solution {
public:
    int snakesAndLadders(vector<vector<int>>& board) {
        int n=board.size();
        vector<pair<int, int>> cells(n*n+1);

        vector<int>columns(n);
        for (int j = 0; j < n; ++j) {
            columns[j] = j;
        }

        int idx=1;
        for(int i=n-1; i>=0; i--) {
            for(int& j : columns) {
                cells[idx++] = {i, j};
            }
            reverse(columns.begin(), columns.end());
        }

        vector<int> dist(n*n+1, -1);
        dist[1]=0;
        queue<int> q;
        q.push(1);

        while(!q.empty()) {
            auto rem = q.front();
            q.pop();

            for(int i=rem+1; i<=min(rem+6, n*n); i++) {
                auto [x, y] = cells[i]; 
                int next_pos = board[x][y] != -1 ? board[x][y] : i;
                if(dist[next_pos] == -1) {
                    dist[next_pos] = dist[rem]+1;
                    q.push(next_pos);
                }
            }
        }

        return dist[n*n];
    }
};