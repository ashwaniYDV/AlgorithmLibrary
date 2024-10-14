// https://leetcode.com/problems/regions-cut-by-slashes/
// https://leetcode.com/problems/regions-cut-by-slashes/editorial/

/*
An n x n grid is composed of 1 x 1 squares where each 1 x 1 square consists of a '/', '\', or blank space ' '. 
These characters divide the square into contiguous regions.
Given the grid grid represented as a string array, return the number of regions.
Note that backslash characters are escaped, so a '\' is represented as '\\'.
*/



/*
Intuition
=========
https://leetcode.com/problems/regions-cut-by-slashes/solutions/205674/dfs-on-upscaled-grid/

We can upscale the input grid to [n * 3][n * 3] grid and draw "lines" there. 
Then, we can paint empty regions using DFS and count them. 
Picture below says it all. 

Note
====
[n * 2][n * 2] grid does not work as "lines" are too thick to identify empty areas correctly.

Explanation: Consider ["//", "/ "]. 

If you only scale it 2x, it looks like this:
0 1 0 1
1 0 1 0
0 1 0 0
1 0 0 0
if you try to search for zeroes in that space, you'll end up with 3 separate islands. 
That's no good. 

So, try scaling it 3x:
0 0 1 0 0 1
0 1 0 0 1 0
1 0 0 1 0 0
0 0 1 0 0 0
0 1 0 0 0 0
1 0 0 0 0 0
Now the zeroes identify as one island, not 3 - perfect!
*/

class Solution {
public:
    int n, N;
    int dx[4] = {-1, 1, 0, 0};
    int dy[4] = {0, 0, -1, 1};

    bool isSafe(int i, int j, vector<vector<int>>& G) {
        return !(i < 0 || i >= N || j < 0 || j >= N || G[i][j] != 0);
    }

    vector<vector<int>> getUpscaledGrid(vector<string>& grid) {
        vector<vector<int>> G(N, vector<int>(N, 0));

        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                int I = i * 3, J = j * 3;
                if(grid[i][j] == '/') {
                    G[I + 0][J + 2] = 1;
                    G[I + 1][J + 1] = 1;
                    G[I + 2][J + 0] = 1;
                }
                if(grid[i][j] == '\\') {
                    G[I + 0][J + 0] = 1;
                    G[I + 1][J + 1] = 1;
                    G[I + 2][J + 2] = 1;
                }
            }
        }

        return G;
    }

    void dfs(int i, int j, vector<vector<int>>& g) {
        if(!isSafe(i, j, g)) return;
        g[i][j] = 2;
        for(int z = 0; z < 4; z++) {
            dfs(i+dx[z], j+dy[z], g);
        }
    }

    int regionsBySlashes(vector<string>& grid) {
        n = grid.size();
        N = 3 * n;
        vector<vector<int>> upscaledGrid = getUpscaledGrid(grid);
        
        int noOfIslands = 0;
        for(int i = 0; i < N; i++) {
            for(int j = 0; j < N; j++) {
                if(upscaledGrid[i][j] == 0) {
                    dfs(i, j, upscaledGrid);
                    noOfIslands++;
                }
            }
        }

        return noOfIslands;
    }
};