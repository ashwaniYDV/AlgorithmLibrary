// https://leetcode.com/problems/path-with-maximum-gold/

class Solution {
public:
    int dx[4] = {0, 1, 0, -1};
    int dy[4] = {-1, 0, 1, 0};
    vector<vector<int>> vis;
    int n, m;
    
    bool isSafe(int i, int j, vector<vector<int>>& mine) {
        if(i < 0 || i >= n || j < 0 || j >= m || vis[i][j] || mine[i][j] == 0)
            return false;
        return true;
    }
    
    int fun(int i, int j, vector<vector<int>>& mine) {
        if(!isSafe(i, j, mine)) {
            return 0;
        }
        
        vis[i][j] = 1;
        
        int res = mine[i][j], sum = 0;
        
        for(int z = 0; z < 4; z++) {
            int ni = i + dx[z], nj = j + dy[z];
            sum = max(sum, fun(ni, nj, mine));
        }
        
        vis[i][j] = 0;
        
        return res + sum;
    }
    
    int getMaximumGold(vector<vector<int>>& mine) {
        n = mine.size(), m = mine[0].size();
        vis.resize(n, vector<int>(m, 0));
        
        int res = 0;
        
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(mine[i][j] > 0) {
                    res = max(res, fun(i, j, mine));
                }
            }
        }
        
        return res;
    }
};
