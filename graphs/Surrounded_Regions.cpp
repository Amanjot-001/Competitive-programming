#include <bits/stdc++.h>

class Solution {
public:
    // dfs on borders to mark all reachable nodes and not reachable as it is.
    int n, m;
    vector<vector<bool>> vis;
    vector<vector<int>> dirs = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};

    void dfs(vector<vector<char>>& board, int r, int c) {
        vis[r][c]=true;
        board[r][c] = 'A';

        for(auto& d : dirs) {
            int rd = r+d[0];
            int cd = c+d[1];

            if(rd<0 || cd<0 || rd>=n || cd>=m || vis[rd][cd] || board[rd][cd] != 'O')
                continue;

            dfs(board, rd, cd);
        }
    }

    void solve(vector<vector<char>>& board) {
        n = board.size();
        m = board[0].size();

        vis.resize(n, vector<bool>(m, false));

        for(int i=0; i<n; i++) {
            for(int j=0; j<m; j++) {
                if(i==0 || j==0 || i==n-1 || j==m-1) {
                    if(!vis[i][j] && board[i][j] == 'O') {
                        dfs(board, i, j);
                    }
                }
            }
        }

        for(int i=0; i<n; i++) {
            for(int j=0; j<m; j++) {
                if(board[i][j] == 'A')
                    board[i][j] = 'O';
                else
                    board[i][j] = 'X';
            }
        }
    }
};
