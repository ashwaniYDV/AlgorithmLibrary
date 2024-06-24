// https://leetcode.com/problems/pacific-atlantic-water-flow/

/*
There is an m x n rectangular island that borders both the Pacific Ocean and Atlantic Ocean. 
Pacific Ocean touches the island's left and top edges.
Atlantic Ocean touches the island's right and bottom edges.

The island is partitioned into a grid of square cells. 
You are given an m x n integer matrix heights where heights[r][c] represents the height above sea level of the cell at coordinate (r, c).

The island receives a lot of rain, and the rain water can flow to neighboring cells directly north, south, east, and west 
if the neighboring cell's height is <= current cell's height. 
Water can flow from any cell adjacent to an ocean into the ocean.

Return a 2D list of grid coordinates result where result[i] = [ri, ci] denotes that 
rain water can flow from cell (ri, ci) to both the Pacific and Atlantic oceans.
*/

/*
Intution
--------
* It is given that water can flow from higher cells to lower cells.
* Hypothetically for now, think in reverse way.
  Water can flow from ocean to higher cells (just think this way hypothetically).
* Since outer bounday cells of grid touches the ocean.
  So water first flows from ocean to outer boundaries.
  Thus we can say that water can flow from outer boundaries to inner boundaries according to cell height conditions.
  height[outer cell] <= height[inner cell]
* This becomes a multi src BFS problem.

* Solve it separately for Pacific and Atlantic ocean.
* A cell will be answer if it is visited in both Pacific and Atlantic oceans multi src BFS.
*/

class Solution {
public:
    int n, m;
    int dx[4] = {1, -1, 0, 0};
    int dy[4] = {0, 0, 1, -1};

    bool isSafe(int i, int j, vector<vector<int>>& vis) {
        if(i < 0 || i >= n || j < 0 || j >= m || vis[i][j]) return false;
        return true;
    }

    void multiSrcBfs(vector<vector<int>>& vis, queue<pair<int, int>>& q, vector<vector<int>>& heights) {
        while(!q.empty()) {
            auto it = q.front();
            q.pop();
            int x = it.first, y = it.second;

            for(int z = 0; z < 4; z++) {
                int nx = x + dx[z], ny = y + dy[z];
                if(!isSafe(nx, ny, vis)) continue;

                if(heights[nx][ny] < heights[x][y]) continue;

                vis[nx][ny] = 1;
                q.push({nx, ny});
            }
        }
    }

    void pacific(vector<vector<int>>& vis1, vector<vector<int>>& heights) {
        queue<pair<int, int>> q1;

        // insert top row and left column in queue
        for(int i = 0; i < n; i++) {
            vis1[i][0] = 1;
            q1.push({i, 0});
        }
        for(int j = 1; j < m; j++) {
            vis1[0][j] = 1;
            q1.push({0, j});
        }

        multiSrcBfs(vis1, q1, heights);
    }

    void atlantic(vector<vector<int>>& vis2, vector<vector<int>>& heights) {
        queue<pair<int, int>> q2;

        // insert bottom row and right column in queue
        for(int i = 0; i < n; i++) {
            vis2[i][m-1] = 1;
            q2.push({i, m-1});
        }
        for(int j = 0; j < m-1; j++) {
            vis2[n-1][j] = 1;
            q2.push({n-1, j});
        }

        multiSrcBfs(vis2, q2, heights);
    }

    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        n = heights.size();
        m = heights[0].size();

        vector<vector<int>> vis1(n, vector<int>(m, 0));
        vector<vector<int>> vis2(n, vector<int>(m, 0));

        pacific(vis1, heights);
        atlantic(vis2, heights);

        vector<vector<int>> res;
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(vis1[i][j] && vis2[i][j]) res.push_back({i, j});
            }
        }

        return res;
    }
};