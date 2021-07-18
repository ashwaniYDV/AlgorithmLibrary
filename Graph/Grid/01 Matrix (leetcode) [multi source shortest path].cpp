// https://leetcode.com/problems/01-matrix/

/*
Given an m x n binary matrix mat, return the distance of the nearest 0 for each cell.
*/


class Solution {
public:
    int n, m;
    vector<vector<int>> vis, dist;
    int dx[4] = {0, 1, 0, -1};
    int dy[4] = {-1, 0, 1, 0};
    
    bool isSafe(int i, int j) {
        if(i < 0 || i >= n || j < 0 || j >= m || vis[i][j])
            return false;
        return true;
    }
    
    void bfs(vector<vector<int>>& matrix) {
        queue<pair<int, int>> q;
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(matrix[i][j] == 0) {
                    q.push({i, j});
                    vis[i][j] = 1;
                    dist[i][j] = 0;
                }
            }
        }

        while(!q.empty()) {
            pair<int, int> x = q.front();
            q.pop();

            for(int z=0; z < 4; z++) {
                int i = x.first + dx[z], j = x.second + dy[z];
                if(!isSafe(i, j)) continue;
                vis[i][j] = 1;
                dist[i][j] = dist[x.first][x.second] + 1;
                q.push({i, j});
            }
        }
    }
    
    vector<vector<int>> updateMatrix(vector<vector<int>>& matrix) {
        n = matrix.size();
        m = matrix[0].size();
        vis.resize(n, vector<int>(m, 0));
        dist.resize(n, vector<int>(m, 0));
        bfs(matrix);
        return dist;
    }
};
