// https://leetcode.com/problems/path-with-minimum-effort/
// https://leetcode.com/problems/path-with-minimum-effort/discuss/909017/JavaPython-Dijikstra-Binary-search-Clean-and-Concise


/*
Note: Open link to see diagrams.

You are a hiker preparing for an upcoming hike. You are given heights, a 2D array of size rows x columns, 
where heights[row][col] represents the height of cell (row, col). 
You are situated in the top-left cell, (0, 0), and you hope to travel to the bottom-right cell, (rows-1, columns-1).
You can move up, down, left, or right, and you wish to find a route that requires the minimum effort.

A route's effort is the maximum absolute difference in heights between two consecutive cells of the route.
Return the minimum effort required to travel from the top-left cell to the bottom-right cell.

 
Example 1:
Input: heights = [[1,2,2],
                  [3,8,2],
                  [5,3,5]]
Output: 2
Explanation: The route of [1,3,5,3,5] has a maximum absolute difference of 2 in consecutive cells.
This is better than the route of [1,2,2,2,5], where the maximum absolute difference is 3.

Example 2:
Input: heights = [[1,2,3],
                  [3,8,4],
                  [5,3,5]]
Output: 1
Explanation: The route of [1,2,3,4,5] has a maximum absolute difference of 1 in consecutive cells, which is better than route [1,3,5,3,5].

Example 3:
Input: heights = [[1,2,1,1,1],
                  [1,2,1,2,1],
                  [1,2,1,2,1],
                  [1,2,1,2,1],
                  [1,1,1,2,1]]
Output: 0
Explanation: This route does not require any effort.
*/





/*
Solution 1: Dijikstra

Idea:
If we observe, this problem is to find the shortest path from a source cell (0, 0) to a destination cell (m-1, n-1). 
Here, the shortest path is the one with minimum distance, 
and distance is defined as maximum absolute difference in heights between two consecutive cells of the path.
Thus, we could use Dijikstra's algorithm which is used to find the shortest path in a weighted graph 
with a slight modification of criteria for the shortest path, which costs O(E log V), where E is number of edges E = 4*M*N, V is number of veritices V = M*N

Complexity:
Time: O(ElogV) = O(M*N log M*N), where M is the number of rows and N is the number of columns in the matrix.
Space: O(M*N)

My understanding of why we can use Dijkstra here:
1) Here, the total path cost is the maximum absolute difference, its a different kind of cost function 
   compared to the vanilla adding all costs together along the path
2) For Dijkstra, edge weight cannot be negative, but what does that really mean. 
   It effectively means total path cost cannot go down when a new edge joins the path. 
   In the vanilla Dijkstra, it's in the form of negative edge weight. 
   If we translate that to this problem, we can see that the total path cost (maximum absolute difference) will never go down when a new edge joins the path.
   That's why we used newDist = max(d, abs(heights[nx][ny] - heights[x][y]));
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

    int minimumEffortPath(vector<vector<int>>& heights) {
        n = heights.size(), m = heights[0].size();
        vector<vector<int>> dist(n, vector<int>(m, INF));

        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;
        // distance, row, col
        pq.push({0, 0, 0});

        while (!pq.empty()) {
            auto it = pq.top();
            pq.pop();
            int d = it[0], x = it[1], y = it[2];
            if (d > dist[x][y]) continue;

            // Reach to bottom right
            if (x == n - 1 && y == m - 1) return d;

            for (int z = 0; z < 4; z++) {
                int nx = x + dx[z], ny = y + dy[z];
                if (!isSafe(nx, ny)) continue;

                int newDist = max(d, abs(heights[nx][ny] - heights[x][y]));
                if (dist[nx][ny] > newDist) {
                    dist[nx][ny] = newDist;
                    pq.push({dist[nx][ny], nx, ny});
                }
            }
        }

        // Unreachable code, C++ require to return interger value.
        return 0;
    }
};

























/*
Solution 2: Binary Search + DFS

Idea:
1) Consider the grid as a graph, where adjacent cells have an edge with cost of the abs difference between the cells.
2) If you are given threshold k, check if it is possible to go from (0, 0) to (n-1, m-1) using only edges of ≤ k cost.
3) Binary search the k value.

Complexity:
Time: O(log(MAX_HEIGHT) * m * n), where MAX_HEIGHT = 10^6
Space: O(m * n)
*/


class Solution {
public:
#define INF 1e9
    int dx[4] = {0, 1, 0, -1};
    int dy[4] = { -1, 0, 1, 0};
    int n, m;

    bool isSafe(int i, int j, vector<vector<int>>& vis) {
        if (i < 0 || i >= n || j < 0 || j >= m || vis[i][j])
            return false;
        return true;
    }

    bool dfs(int i, int j, int threadshold, vector<vector<int>>& vis, vector<vector<int>>& heights) {
        if (i == n - 1 and j == m - 1) return true;

        vis[i][j] = 1;

        for (int z = 0; z < 4; z++) {
            int ni = i + dx[z], nj = j + dy[z];
            if (!isSafe(ni, nj, vis)) continue;
            if (abs(heights[ni][nj] - heights[i][j]) > threadshold) continue;

            if (dfs(ni, nj, threadshold, vis, heights)) return true;
        }

        return false;
    }

    bool canReachDestination(int threadshold, vector<vector<int>>& heights) {
        vector<vector<int>> vis(n, vector<int>(m, 0));
        return dfs(0, 0, threadshold, vis, heights);
    }

    int minimumEffortPath(vector<vector<int>>& heights) {
        n = heights.size(), m = heights[0].size();

        int left = 0;
        int ans = 1e6, right = 1e6;
        while (left < right) {
            int mid = left + (right - left) / 2;
            if (canReachDestination(mid, heights)) {
                right = mid;
            } else {
                left = mid + 1;
            }
        }
        return left;
    }
};
