// https://leetcode.com/problems/island-perimeter/

/*
You are given row x col grid representing a map where grid[i][j] = 1 represents land and grid[i][j] = 0 represents water.
Grid cells are connected horizontally/vertically (not diagonally). The grid is completely surrounded by water, and there is exactly one island 
(i.e., only one connected component).
The island doesn't have "lakes", meaning the water inside isn't connected to the water around the island. 
One cell is a square with side length 1. The grid is rectangular, width and height don't exceed 100. Determine the perimeter of the island.
*/

class Solution {
public:
    int dx[4] = {0, 1, 0, -1};
    int dy[4] = {-1, 0, 1, 0};
    
    int n, m, perimeter = 0;
    vector<vector<int>> vis;
    
    bool isSafe(int i, int j, vector<vector<int>>& grid) {
        if(i < 0 || i >= n || j < 0 || j >= m || grid[i][j] == 0 || vis[i][j]) return false;
        return true;
    }
    
    void dfs(int i, int j, vector<vector<int>>& grid) {
        if(!isSafe(i, j, grid)) return;

        int cnt = 4;
        if(i - 1 >= 0 && grid[i-1][j] == 1) cnt--;
        if(i +1 < n && grid[i+1][j] == 1) cnt--;
        if(j + 1 < m && grid[i][j+1] == 1) cnt--;
        if(j - 1 >= 0 && grid[i][j-1] == 1) cnt--;
        
        perimeter += cnt;
        
        vis[i][j] = 1;

        for(int z = 0; z < 4; z++) {
            dfs(i + dx[z], j + dy[z], grid);
        }
    }
    
    int islandPerimeter(vector<vector<int>>& grid) {
        n = grid.size();
        if(n == 0) return 0;
        m = grid[0].size();
        if(m == 0) return 0;
        
        vis.resize(n+1, vector<int>(m+1, 0));
        
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(grid[i][j] == 1) {
                    dfs(i, j, grid);
                    return perimeter;
                }
            }
        }
        
        return 0;
    }
};
