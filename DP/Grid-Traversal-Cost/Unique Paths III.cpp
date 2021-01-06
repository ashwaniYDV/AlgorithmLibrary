// https://leetcode.com/problems/unique-paths-iii/

/* The constraints are:
(i) Each and every non-obstacle square must be visited
(ii) Each and every non-obstacle square must be visited exactly once
*/

class Solution {
public:
    int n, m, x1, y1, x2, y2, ans = 0, zeros = 0;
    int dirx[4] = {1, -1, 0, 0};
    int diry[4] = {0, 0, 1, -1};
    
    int isSafe(int x, int y, vector<vector<int>>& grid) {
        if(x >= 0 && x < n && y >= 0 && y < m && grid[x][y] != -1) return 1;
        return 0;
    }
    
    // NOTE: &grid and grid both will work
    void dfs(int x, int y, vector<vector<int>>& grid, int cnt){
        if(!isSafe(x, y, grid)) return;
        
        if(x == x2 && y == y2){
            if(cnt - 1 == zeros) ans++;
            return;
        }
        
        // mark as visited
        grid[x][y] = -1;
        for(int i = 0; i < 4; i++){
            int xx = x + dirx[i];
            int yy = y + diry[i];
            dfs(xx, yy, grid, cnt + 1);
        }
        // backtrack
        grid[x][y] = 0;
    }
    int uniquePathsIII(vector<vector<int>>& grid) {
        n = grid.size();
        if(n==0) return 0;
        m = grid[0].size();
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(grid[i][j] == 1){
                    x1 = i;
                    y1 = j;
                }
                if(grid[i][j] == 2){
                    x2 = i;
                    y2 = j;
                }
                if(grid[i][j] == 0){
                    zeros++;
                }
            }
        }
        dfs(x1, y1, grid, 0);
        return ans;
    }
};
