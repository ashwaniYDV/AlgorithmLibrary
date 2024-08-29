// https://leetcode.com/problems/minimum-number-of-days-to-disconnect-island/
// https://leetcode.com/problems/minimum-number-of-days-to-disconnect-island/solutions/819296/dfs-c-clean-code-with-explanation/

/*
You are given an m x n binary grid grid where 1 represents land and 0 represents water. 
An island is a maximal 4-directionally (horizontal or vertical) connected group of 1's.
The grid is said to be connected if we have exactly one island, otherwise is said disconnected.
In one day, we are allowed to change any single land cell (1) into a water cell (0).
Return the minimum number of days to disconnect the grid.

Input: grid = [[0,1,1,0],[0,1,1,0],[0,0,0,0]]
Output: 2
Explanation: We need at least 2 days to get a disconnected grid.
Change land grid[1][1] and grid[0][2] to water and get 2 disconnected island.

Input: grid = [[1,1]]
Output: 2
Explanation: Grid of full water is also disconnected ([[1,1]] -> [[0,0]]), 0 islands.
*/


/*
Observation (Articulation point concept)
----------------------------------------
* answer is always <= 2

* Why?
  for any island we can remove the two blocks around the bottom left corner to make it disconnected

x x x                          x x x
x . x    can be changed to     x . .
x x x                          x . x


We need to check for only when ans is 1 or 0 (otherwise we can return 2):
a) ans = 1
   we remove a block and check if it disconnects the islands
   i.e. this block is an articulation point

b) ans = 0
   we check if there are > 1 islands already

c) ans = 2
   otherwise in rest of the cases
*/


// Time = O((n * m)^ 2)
class Solution {
public:
    int n, m;
    vector<int> dx = {1, -1, 0, 0};
    vector<int> dy = {0, 0, 1, -1};

    bool isSafe(int x, int y, vector<vector<int>> &grid, vector<vector<int>> & vis) {
        return !(x < 0 || x >= n || y < 0 || y >= m || vis[x][y] || grid[x][y] == 0);
    }

    void dfs(int x, int y, vector<vector<int>> &grid, vector<vector<int>> & vis) {
        vis[x][y] = 1;
        for (int z = 0; z < 4; z++) {
            int nx = x + dx[z];
            int ny = y + dy[z];
            if (isSafe(nx, ny, grid, vis)) dfs(nx, ny, grid, vis);
        }
    }

    int count_islands(vector<vector<int>> & grid) {
        int islands = 0;
        vector<vector<int>> vis(n, vector<int> (m, 0));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (!vis[i][j] and grid[i][j]) {
                    dfs(i, j, grid, vis);
                    islands ++;
                }
            }
        }
        return islands;
    }

    int minDays(vector<vector<int>>& grid) {
        n = grid.size(), m = grid[0].size();

        int islands = count_islands(grid);

        // check for 0 ans
        if (islands > 1 || islands == 0) {
            return 0;
        }

        // check for 1 ans
        // Note: we can use articulation point concept here to optimize this condition of ans = 1
        for (int i = 0 ; i < n; i ++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 1) {
                    // remove this block
                    grid[i][j] = 0;

                    islands = count_islands(grid);

                    if (islands > 1 or islands == 0) return 1;
                    
                    // add back the block
                    grid[i][j] = 1;
                }

            }
        }
        
        // else
        return 2;
    }
};