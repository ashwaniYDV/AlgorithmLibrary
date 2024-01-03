// https://leetcode.com/problems/shortest-path-in-a-grid-with-obstacles-elimination/

/*
You are given an m x n integer matrix grid where each cell is either 0 (empty) or 1 (obstacle). 
You can move up, down, left, or right from and to an empty cell in one step.
Return the minimum number of steps to walk from the upper left corner (0, 0) to the lower right corner (m - 1, n - 1) 
given that you can eliminate at most k obstacles. 
If it is not possible to find such walk return -1.
*/


// Method 1: Using normal queue instead of priority_queue
/*
priority_queue was giving TLE.
Since all edge weights are 1, we can use a normal queue.
*/
class Solution {
public:
    #define INF 1e9
    int dx[4] = {0, 1, 0, -1};
    int dy[4] = { -1, 0, 1, 0};
    int n, m;

    bool isSafe(int i, int j) {
        if (i < 0 || i >= n || j < 0 || j >= m)
            return false;
        return true;
    }

    int shortestPath(vector<vector<int>>& grid, int k) {
        n = grid.size(), m = grid[0].size();
        vector<vector<vector<int> > > dist(n, vector<vector<int> >(m, vector<int>(k+1, INF)));

        queue<vector<int>> q;
        // row, col, j
        q.push({0, 0, 0});
        dist[0][0][0] = 0;

        while (!q.empty()) {
            auto it = q.front();
            q.pop();
            int x = it[0], y = it[1], j = it[2];

            for (int z = 0; z < 4; z++) {
                int nx = x + dx[z], ny = y + dy[z];
                if (!isSafe(nx, ny)) continue;

                if(grid[nx][ny] == 0) {
                    if (dist[nx][ny][j] > dist[x][y][j] + 1) {
                        dist[nx][ny][j] = dist[x][y][j] + 1;
                        q.push({nx, ny, j});
                    }
                }
                if(grid[nx][ny] == 1) {
                    if (j < k && dist[nx][ny][j + 1] > dist[x][y][j] + 1) {
                        dist[nx][ny][j + 1] = dist[x][y][j] + 1;
                        q.push({nx, ny, j + 1});
                    }
                }
            }
        }

        int res = INF;
        for(int z = 0; z <= k; z++) {
            res = min(res, dist[n-1][m-1][z]);
        }
        
        return (res == INF ? -1 : res);
    }
};


// Method 2: TLE
class Solution {
public:
    #define INF 1e9
    int dx[4] = {0, 1, 0, -1};
    int dy[4] = { -1, 0, 1, 0};
    int n, m;

    bool isSafe(int i, int j) {
        if (i < 0 || i >= n || j < 0 || j >= m)
            return false;
        return true;
    }


    int shortestPath(vector<vector<int>>& grid, int k) {
        n = grid.size(), m = grid[0].size();
        vector<vector<vector<int> > > dist(n, vector<vector<int> >(m, vector<int>(k+1, INF)));

        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;
        // distance, row, col, j
        pq.push({0, 0, 0, 0});
        dist[0][0][0] = 0;

        while (!pq.empty()) {
            auto it = pq.top();
            pq.pop();
            int d = it[0], x = it[1], y = it[2], j = it[3];

            for (int z = 0; z < 4; z++) {
                int nx = x + dx[z], ny = y + dy[z];
                if (!isSafe(nx, ny)) continue;

                if(grid[nx][ny] == 0) {
                    if (dist[nx][ny][j] > dist[x][y][j] + 1) {
                        dist[nx][ny][j] = dist[x][y][j] + 1;
                        pq.push({dist[nx][ny][j], nx, ny, j});
                    }
                }
                if(grid[nx][ny] == 1) {
                    if (j < k && dist[nx][ny][j + 1] > dist[x][y][j] + 1) {
                        dist[nx][ny][j + 1] = dist[x][y][j] + 1;
                        pq.push({dist[nx][ny][j + 1], nx, ny, j + 1});
                    }
                }
            }
        }

        int res = INF;
        for(int z = 0; z <= k; z++) {
            res = min(res, dist[n-1][m-1][z]);
        }
        
        return (res == INF ? -1 : res);
    }
};
