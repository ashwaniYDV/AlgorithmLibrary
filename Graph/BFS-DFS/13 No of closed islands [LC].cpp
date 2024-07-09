// https://leetcode.com/problems/number-of-closed-islands/

/*
Given a 2D grid consists of 0s (land) and 1s (water).  
An island is a maximal 4-directionally connected group of 0s and a closed island is an island totally (all left, top, right, bottom) surrounded by 1s.
Return the number of closed islands.
*/


// we have to find no of islands not touching outer boundaries
class Solution {
public:
    int m, n;
    int dx[4] = {-1,0,1,0};
    int dy[4] = {0, 1, 0, -1};

    bool isSafe(int i, int j, vector<vector<int>>& grid) {
        return !(i < 0 || j < 0 || i >= n || j >= m || grid[i][j] == 1);
    }

    void dfs(int i, int j, vector<vector<int>>& grid){
        // mark as visited
        grid[i][j] = 1;

        for(int z = 0; z < 4; z++) {
            int ni = i + dx[z];
            int nj = j + dy[z];
            if(!isSafe(ni, nj, grid)) continue;
            dfs(ni, nj, grid);
        }
    }

    int closedIsland(vector<vector<int>>& grid) {
        n = grid.size(), m = grid[0].size();

        // first visit boundary touching islands and mark them as visited / invalid
        for(int i = 0; i < n; i++) {
            if(grid[i][0] == 0) dfs(i, 0, grid); 
            if(grid[i][m-1] == 0) dfs(i, m-1, grid); 
        }
        for(int j = 1; j < m-1; j++) {
            if(grid[0][j] == 0) dfs(0, j, grid); 
            if(grid[n-1][j] == 0) dfs(n-1, j, grid);
        }

        int islandCnt = 0;
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++){
                if(grid[i][j] == 0) {
                    dfs(i, j, grid);
                    islandCnt++;
                }
            }
        }

        return islandCnt;
    }
};