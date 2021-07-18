// https://leetcode.com/problems/longest-increasing-path-in-a-matrix/

/*
Given an n x m integers matrix, return the length of the longest increasing path in matrix.
From each cell, you can either move in four directions: left, right, up, or down. 
You may not move diagonally or move outside the boundary (i.e., wrap-around is not allowed).
Input: matrix = [[9,9,4],
                 [6,6,8],
                 [2,1,1]]
Output: 4
Explanation: The longest increasing path is [1, 2, 6, 9].
Input: matrix = [[3,4,5],
                 [3,2,6],
                 [2,2,1]]
Output: 4
Explanation: The longest increasing path is [3, 4, 5, 6]. Moving diagonally is not allowed.
*/

// Method 1.1
class Solution {
public:
    int n, m;
    int dx[4] = {0, 1, 0, -1};
    int dy[4] = { -1, 0, 1, 0};
    vector<vector<int>> dp;

    bool isSafe(int i, int j) {
        if(i < 0 || i >= n || j < 0 || j >= m)
            return false;
        return true;
    }
    
    int dfs(int i, int j, vector<vector<int>>& matrix) {
        if(dp[i][j]) return dp[i][j];
        
        for(int z = 0; z < 4; z++) {
            int ni = i + dx[z], nj = j + dy[z];
            if(!isSafe(ni, nj)) continue;
            if (matrix[ni][nj] <= matrix[i][j]) continue;
            
            dp[i][j] = max(dp[i][j], 1 + dfs(ni, nj, matrix));
        }
        
        return dp[i][j];
    }
    
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        n = matrix.size(), m = matrix[0].size();
        dp = vector<vector<int>>(n, vector<int>(m, 0));
        
        int res = 0;
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                res = max(res, dfs(i, j, matrix));
            }
        }
        return res + 1;
    }
};






// Method 1.2
class Solution {
public:
    int n, m;
    int dx[4] = {0, 1, 0, -1};
    int dy[4] = { -1, 0, 1, 0};
    vector<vector<int>> dp;

    bool isSafe(int i, int j) {
        if(i < 0 || i >= n || j < 0 || j >= m)
            return false;
        return true;
    }
    
    int dfs(int i, int j, vector<vector<int>>& matrix) {
        if(dp[i][j] != -1) return dp[i][j];
        dp[i][j] = 0;
        
        for(int z = 0; z < 4; z++) {
            int ni = i + dx[z], nj = j + dy[z];
            if(!isSafe(ni, nj)) continue;
            if (matrix[ni][nj] <= matrix[i][j]) continue;
            
            dp[i][j] = max(dp[i][j], 1 + dfs(ni, nj, matrix));
        }
        
        return dp[i][j];
    }
    
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        n = matrix.size(), m = matrix[0].size();
        dp = vector<vector<int>>(n, vector<int>(m, -1));
        
        int res = 0;
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                res = max(res, dfs(i, j, matrix));
            }
        }
        return res + 1;
    }
};





// Method 1.3
class Solution {
public:
    int n, m;
    int dx[4] = {0, 1, 0, -1};
    int dy[4] = { -1, 0, 1, 0};
    

    bool isSafe(int i, int j) {
        if(i < 0 || i >= n || j < 0 || j >= m)
            return false;
        return true;
    }
    
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        n = matrix.size(), m = matrix[0].size();
        vector<vector<int>> dp(n, vector<int>(m, 0));
        
        std::function<int(int, int)> dfs = [&] (int i, int j) {
            if (dp[i][j]) return dp[i][j];
            
            for (int z = 0; z < 4; z++) {
                int ni = i + dx[z], nj = j + dy[z];
                if(!isSafe(ni, nj)) continue;
                if (matrix[ni][nj] <= matrix[i][j]) continue;

                dp[i][j] = max(dp[i][j], 1 + dfs(ni, nj));
            }
            
            return dp[i][j];
        };
        
        int res = 0;
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                res = max(res, dfs(i, j));
            }
        }
        return res + 1;
    }
};


















// Method 2: Topological Sort
class Solution {
public:
    int n, m;
    int dx[4] = {0, 1, 0, -1};
    int dy[4] = { -1, 0, 1, 0};
    vector<vector<int>> indegree;
    

    bool isSafe(int i, int j) {
        if(i < 0 || i >= n || j < 0 || j >= m)
            return false;
        return true;
    }
    
    int kahn(vector<vector<int>>& matrix) {
        queue<pair<int, int>> q;
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(indegree[i][j] == 0) q.push({i, j});
            }
        }

        int level = 0;
        while(!q.empty()) {
            int sz = q.size();
            for(int i = 0; i < sz; i++) {
                auto it = q.front();
                q.pop();
                int x = it.first, y = it.second;

                for (int z = 0; z < 4; z++) {
                    int nx = x + dx[z], ny = y + dy[z];
                    if(!isSafe(nx, ny)) continue;
                    if (matrix[nx][ny] <= matrix[x][y]) continue;
                    indegree[nx][ny]--;
                    if(indegree[nx][ny] == 0) {
                        q.push({nx, ny});
                    }
                }
            }
            level++;
        }
        return level;
    }
    
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        n = matrix.size(), m = matrix[0].size();
        indegree = vector<vector<int>>(n, vector<int>(m, 0));

        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                for (int z = 0; z < 4; z++) {
                    int ni = i + dx[z], nj = j + dy[z];
                    if(!isSafe(ni, nj)) continue;
                    if (matrix[ni][nj] <= matrix[i][j]) continue;
                    indegree[ni][nj]++;
                }
            }
        }
        return kahn(matrix);
    }
};




















// Method 3
class Solution {
public:
    int n, m;
    int dx[4] = {0, 1, 0, -1};
    int dy[4] = { -1, 0, 1, 0};
    vector<vector<int>> vis, dp;

    bool isSafe(int i, int j) {
        if(i < 0 || i >= n || j < 0 || j >= m)
            return false;
        return true;
    }

    void dfs(int i, int j, vector<vector<int>>& matrix) {
        vis[i][j] = 1;
        dp[i][j] = 0;

        for(int z = 0; z < 4; z++) {
            int ni = i + dx[z], nj = j + dy[z];
            if(!isSafe(ni, nj)) continue;
            if(matrix[ni][nj] <= matrix[i][j]) continue;

            if(!vis[ni][nj]) {
                dfs(ni, nj, matrix);
            }

            dp[i][j] = max(dp[i][j], 1 + dp[ni][nj]);
        }
    }
    
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        n = matrix.size(), m = matrix[0].size();
        vis = vector<vector<int>>(n, vector<int>(m, 0));
        dp = vector<vector<int>>(n, vector<int>(m, 0));
        
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(!vis[i][j]) dfs(i, j, matrix);
            }
        }
        
        int res = 0;
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                res = max(res, dp[i][j]);
            }
        }
        return res + 1;
    }
};
