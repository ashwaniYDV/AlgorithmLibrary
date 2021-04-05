// https://leetcode.com/problems/shortest-bridge/

/*
The idea I used in this problem is that. (Note that there is exactly two group of islands).
(1) I will traverse one group of island by DFS and mark this group from number 1 to number 2
    So now the grid has one group of island with number 2 and the other group of island with number 1 and the rest of the grid is number 0.
(2) Now I will do multisource BFS from all the grid[i][j] with value as 2.
(3) Now the final answer will be minimum of all the distances of grid[i][j] with value 1.
(4) So minimum number of flips required is (mn - 1).
*/


// Method 1
class Solution {
public:
    int n, m;
    int dx[4] = {0, 1, 0, -1};
    int dy[4] = {-1, 0, 1, 0};
    
    bool isSafeBFS(int i, int j, vector<vector<int>>& dis) {
        if(i < 0 || i >= n || j < 0 || j >= m || dis[i][j] != 1e9) 
            return false;
        return true;
    }
    int multiSourceBFS(vector<vector<int>>& A) {
        vector<vector<int>> dis(n, vector<int>(m, 1e9));
        queue<pair<int, int>> q;
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(A[i][j] == 2) {
                    q.push({i, j});
                    dis[i][j] = 0;
                }
            }
        }

        while (!q.empty()) {
            auto x = q.front();
            q.pop();
            int i = x.first, j = x.second;
            
            if(A[i][j] == 1) {
                return dis[i][j] - 1;
            }

            for(int z = 0; z < 4; z++) {
                int ni = i + dx[z], nj = j + dy[z];
                if(!isSafeBFS(ni, nj, dis)) continue;
            
                dis[ni][nj] = dis[i][j] + 1;
                q.push({ni, nj});
            }
        }

        return 0;
    }
    
    bool isSafeDFS(int i, int j, vector<vector<int>>& A) {
        if(i < 0 || i >= n || j < 0 || j >= m || A[i][j] == 0 || A[i][j] == 2) 
            return false;
        return true;
    }
    void dfs(int i, int j, vector<vector<int>>& A) {
        if (!isSafeDFS(i, j, A)) {
            return;
        }
        
        A[i][j] = 2;
        for(int z = 0; z < 4; z++) {
            dfs(i + dx[z], j + dy[z], A);
        }
    }
    
    int shortestBridge(vector<vector<int>>& A) {
        n = A.size(), m = A[0].size();
        
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(A[i][j] == 1) {
                    dfs(i, j, A);
                    return multiSourceBFS(A);
                }
            }
        }
        
        return 0;
    }
};






















// Method 2
class Solution {
public:
    int n, m;
    int dx[4] = {0, 1, 0, -1};
    int dy[4] = {-1, 0, 1, 0};
    
    bool isSafeBFS(int i, int j, vector<vector<int>>& dis) {
        if(i < 0 || i >= n || j < 0 || j >= m || dis[i][j] != 1e9) 
            return false;
        return true;
    }
    int multiSourceBFS(vector<vector<int>>& A) {
        vector<vector<int>> dis(n, vector<int>(m, 1e9));
        queue<pair<int, int>> q;
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(A[i][j] == 2) {
                    q.push({i, j});
                    dis[i][j] = 0;
                }
            }
        }

        while (!q.empty()) {
            auto x = q.front();
            q.pop();
            int i = x.first, j = x.second;

            for(int z = 0; z < 4; z++) {
                int ni = i + dx[z], nj = j + dy[z];
                if(!isSafeBFS(ni, nj, dis)) continue;
            
                dis[ni][nj] = dis[i][j] + 1;
                q.push({ni, nj});
            }
        }

        int mn = 1e9;
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(A[i][j] == 1) {
                    mn = min(mn, dis[i][j]);
                }
            }
        }
        
        return mn - 1;
    }
    
    bool isSafeDFS(int i, int j, vector<vector<int>>& A) {
        if(i < 0 || i >= n || j < 0 || j >= m || A[i][j] == 0 || A[i][j] == 2) 
            return false;
        return true;
    }
    void dfs(int i, int j, vector<vector<int>>& A) {
        if (!isSafeDFS(i, j, A)) {
            return;
        }
        
        A[i][j] = 2;
        for(int z = 0; z < 4; z++) {
            dfs(i + dx[z], j + dy[z], A);
        }
    }
    
    int shortestBridge(vector<vector<int>>& A) {
        n = A.size(), m = A[0].size();
        
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(A[i][j] == 1) {
                    dfs(i, j, A);
                    return multiSourceBFS(A);
                }
            }
        }
        
        return 0;
    }
};
