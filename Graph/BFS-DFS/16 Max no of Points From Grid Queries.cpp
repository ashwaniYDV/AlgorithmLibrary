// http://leetcode.com/problems/maximum-number-of-points-from-grid-queries/

/*
You are given an m x n integer matrix grid and an array queries of size k.
Find an array answer of size k such that for each integer queries[i] you start in the top left cell of the matrix and repeat the following process:
  * If queries[i] is strictly greater than the value of the current cell that you are in, then you get one point if it is your first time visiting this cell, 
    and you can move to any adjacent cell in all 4 directions: up, down, left, and right.
  * Otherwise, you do not get any points, and you end this process.
After the process, answer[i] is the maximum number of points you can get. 
Note that for each query you are allowed to visit the same cell multiple times.
Return the resulting array answer.


Input: grid = [[1,2,3],[2,5,7],[3,5,1]], queries = [5,6,2]
Output: [5,8,1]
Explanation: The diagrams above show which cells we visit to get points for each query.

Input: grid = [[5,2,1],[1,1,2]], queries = [3]
Output: [0]
Explanation: We can not get any points because the value of the top left cell is already greater than or equal to 3.
 

Constraints:
m == grid.length
n == grid[i].length
2 <= m, n <= 1000
4 <= m * n <= 10^5
k == queries.length
1 <= k <= 10^4
1 <= grid[i][j], queries[i] <= 10^6
*/


// TLE Solution
class Solution {
public:
    int n, m;
    int dx[4] = {0, 0, 1, -1};
    int dy[4] = {1, -1, 0, 0};

    bool isSafe(int i, int j, vector<vector<bool>>& vis) {
        return (i >= 0 && i < n && j >= 0 && j < m && !vis[i][j]);
    }

    void dfs(int i, int j, int& count, int q, vector<vector<bool>>& vis, vector<vector<int>>& grid) {
        if (!isSafe(i, j, vis) || grid[i][j] >= q) return;

        count++;
        vis[i][j] = 1;

        for(int z = 0; z < 4; z++) {
            dfs(i + dx[z], j + dy[z], count, q, vis, grid);
        }
    }

    vector<int> maxPoints(vector<vector<int>>& grid, vector<int>& queries) {
        n = grid.size(), m = grid[0].size();
        vector<int> res;

        for(int q: queries) {
            vector<vector<bool>> vis(n, vector<bool>(m, 0));
            int count = 0;
            // this dfs check how many elements are less than or equal to q which form connected component via (0, 0)
            dfs(0, 0, count, q, vis, grid);
            res.push_back(count);
        }
        return res;
    }
};



// Method 1
class Solution {
public:
    int dx[4] = {0, 0, 1, -1};
    int dy[4] = {1, -1, 0, 0};

    bool isSafe(int i, int j, int n, int m, vector<vector<bool>>& vis) {
        return (i >= 0 && i < n && j >= 0 && j < m && !vis[i][j]);
    }

    vector<int> maxPoints(vector<vector<int>>& grid, vector<int>& queries) {
        int n = grid.size(), m = grid[0].size();

        vector<array<int, 2>> sortedQueries;
        for (int i = 0; i < queries.size(); i++) {
            sortedQueries.push_back({queries[i], i});
        }
        sort(sortedQueries.begin(), sortedQueries.end());

        vector<int> res(queries.size(), 0);

        // Min-heap to process cells in increasing order of value
        priority_queue<array<int, 3>, vector<array<int, 3>>, greater<>> pq;
        vector<vector<bool>> vis(n, vector<bool>(m, false));

        int totalPoints = 0;
        pq.push({grid[0][0], 0, 0});
        vis[0][0] = true;

        // Process queries in sorted order
        for (auto [queryVal, queryIdx] : sortedQueries) {
            // Expand the cells that are smaller than the current query value
            while (!pq.empty() && pq.top()[0] < queryVal) {
                auto [u, i, j] = pq.top();
                pq.pop();

                // Increment count of valid cells
                totalPoints++;

                for (int z = 0; z < 4; z++) {
                    int ni = i + dx[z], nj = j + dy[z];

                    if(isSafe(ni, nj, n, m, vis)) {
                        pq.push({grid[ni][nj], ni, nj});
                        vis[ni][nj] = true;
                    }
                }
            }

            res[queryIdx] = totalPoints;
        }
        
        return res;
    }
};
