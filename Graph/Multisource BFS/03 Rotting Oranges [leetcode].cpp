// https://leetcode.com/problems/rotting-oranges/

/*
You are given an m x n grid where each cell can have one of three values:
0: representing an empty cell,
1: representing a fresh orange, or
2: representing a rotten orange.
Every minute, any fresh orange that is 4-directionally adjacent to a rotten orange becomes rotten.

Return the minimum number of minutes that must elapse until no cell has a fresh orange. If this is impossible, return -1.
*/

class Solution {
public:
    #define INF 1e9
    int dx[4] = {0, 1, 0, -1};
    int dy[4] = {-1, 0, 1, 0};
    int n, m;
    
    bool isSafe(int i, int j, vector<vector<int>>& vis, vector<vector<int>>& grid) {
        if(i < 0 || i >= n || j < 0 || j >= m || vis[i][j] || grid[i][j] == 0)
            return false;
        return true;
    }
    int orangesRotting(vector<vector<int>>& grid) {
        n = grid.size();
        m = grid[0].size();
        
        vector<vector<int>> vis(n, vector<int>(m, 0));
        vector<vector<int>> time(n, vector<int>(m, INF));
        
        queue<pair<int, int>> q;
        
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(grid[i][j] == 2) {
                    time[i][j] = 0;
                    vis[i][j] = 1;
                    q.push({i, j});
                }
            }
        }
        
        while(!q.empty()) {
            auto it = q.front();
            q.pop();
            int x = it.first, y = it.second;
            
            for(int z = 0; z < 4; z++) {
                int nx = x + dx[z], ny = y + dy[z];
                if(isSafe(nx, ny, vis, grid)) {
                    time[nx][ny] = time[x][y] + 1;
                    vis[nx][ny] = 1;
                    q.push({nx, ny});
                }
            }
        }
        
        int mx = 0;
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(grid[i][j] == 1) {
                    if(time[i][j] == INF) return -1;
                    mx = max(mx, time[i][j]);
                }
            }
        }
        return mx;
    }
};
