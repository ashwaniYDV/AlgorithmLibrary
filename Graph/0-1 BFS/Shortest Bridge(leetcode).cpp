// https://leetcode.com/problems/shortest-bridge/

class Solution {
public:
    int n, m;
    int dx[4] = {0, 1, 0, -1};
    int dy[4] = {-1, 0, 1, 0};
    
    bool isSafeBFS(int i, int j) {
        if(i < 0 || i >= n || j < 0 || j >= m) 
            return false;
        return true;
    }
    int bfs_01(pair<int, int> src, vector<vector<int>>& A) {
        vector<vector<int>> dis(n, vector<int>(m, 1e9));
        deque<pair<int, int>> dq;
        dq.push_front(src);
        dis[src.first][src.second] = 0;

        while (!dq.empty()) {
            auto x = dq.front();
            dq.pop_front();
            int i = x.first, j = x.second;

            for(int z = 0; z < 4; z++) {
                int ni = i + dx[z], nj = j + dy[z];
                if(!isSafeBFS(ni, nj)) continue;
                
                int w = (A[ni][nj] == 2) ? 0 : 1;
                if (dis[ni][nj] > dis[i][j] + w) {
                    dis[ni][nj] = dis[i][j] + w;
                    if (w == 0) {
                        dq.push_front({ni, nj});
                    } else {
                        dq.push_back({ni, nj});
                    }
                }
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
    
    bool isSafe(int i, int j, vector<vector<int>>& A) {
        if(i < 0 || i >= n || j < 0 || j >= m || A[i][j] == 0 || A[i][j] == 2) 
            return false;
        return true;
    }
    void dfs(int i, int j, vector<vector<int>>& A) {
        if (!isSafe(i, j, A)) {
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
                    return bfs_01({i, j}, A);
                }
            }
        }
        
        return 0;
    }
};
