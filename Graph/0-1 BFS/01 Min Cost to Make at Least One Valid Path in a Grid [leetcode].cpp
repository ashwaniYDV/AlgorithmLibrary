// https://leetcode.com/problems/minimum-cost-to-make-at-least-one-valid-path-in-a-grid/

/*
Given a m x n grid. Each cell of the grid has a sign pointing to the next cell you should visit if you are currently in this cell. 
The sign of grid[i][j] can be:
1 -> which means go to the cell to the right. (i.e go from grid[i][j] to grid[i][j + 1])
2 -> which means go to the cell to the left. (i.e go from grid[i][j] to grid[i][j - 1])
3 -> which means go to the lower cell. (i.e go from grid[i][j] to grid[i + 1][j])
4 -> which means go to the upper cell. (i.e go from grid[i][j] to grid[i - 1][j])
Notice that there could be some invalid signs on the cells of the grid which points outside the grid.

You will initially start at the upper left cell (0,0). A valid path in the grid is a path which starts from the upper left cell (0,0) 
and ends at the bottom-right cell (m - 1, n - 1) following the signs on the grid. The valid path doesn't have to be the shortest.

You can modify the sign on a cell with cost = 1. You can modify the sign on a cell one time only.
Return the minimum cost to make the grid have at least one valid path.
*/


class Solution {
public:
    const int INF = 1e9;
    int dx[4] = {0, 1, 0, -1};
    int dy[4] = { -1, 0, 1, 0};
    vector<int> stepDir = {2, 3, 1, 4};

    int n, m;
    vector<vector<int>> dis;

    bool isSafe(int x, int y) {
        if(x < 0 || x >= n || y < 0 || y >= m)
            return false;
        return true;
    }

    int bfs01(vector<vector<int>>& g) {
        dis = vector<vector<int>>(n, vector<int>(m, INF));
        deque<pair<int, int>> dq;
        dq.push_front({0, 0});
        dis[0][0] = 0;

        while (!dq.empty()) {
            auto it = dq.front();
            dq.pop_front();
            int x = it.first, y = it.second;

            for(int z = 0; z < 4; z++) {
                int nx = x + dx[z], ny = y + dy[z];
                if(!isSafe(nx, ny)) continue;

                int w = 1;
                if(g[x][y] == stepDir[z]) w = 0;

                if (dis[nx][ny] > dis[x][y] + w) {
                    dis[nx][ny] = dis[x][y] + w;
                    if (w == 0) {
                        dq.push_front({nx, ny});
                    } else {
                        dq.push_back({nx, ny});
                    }
                }
            }
        }

        return dis[n - 1][m - 1];
    }

    int minCost(vector<vector<int>>& grid) {
        n = grid.size(), m = grid[0].size();
        return bfs01(grid);
    }
};
