// https://leetcode.com/problems/longest-increasing-path-in-a-matrix/description/

/*
Given an m x n integers matrix, return the length of the longest increasing path in matrix.
From each cell, you can either move in four directions: left, right, up, or down. 
You may not move diagonally or move outside the boundary (i.e., wrap-around is not allowed).
*/

/*
Consider:
  a cell in the matrix as a node,
  a directed edge from node x to node y if x and y are adjacent and x's value < y's value

Then a graph is formed.
No cycles can exist in the graph, i.e. a DAG is formed.
The problem becomes to get the longest path in the DAG.
Topological sort can iterate the vertices of a DAG in the linear ordering.
Using Kahn's algorithm(BFS) to implement topological sort while counting the levels can give us the longest chain of nodes in the DAG.
*/



class Solution {
public:
    int n, m;
    int dx[4] = {0, 1, 0, -1};
    int dy[4] = { -1, 0, 1, 0};
    vector<vector<int>> indegree;
    

    bool isSafe(int i, int j) {
        if(i < 0 || i >= n || j < 0 || j >= m)
            return false;
        return true;
    }
    
    int kahn(vector<vector<int>>& matrix) {
        queue<pair<int, int>> q;
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(indegree[i][j] == 0) q.push({i, j});
            }
        }

        int level = 0;
        while(!q.empty()) {
            int sz = q.size();
            for(int i = 0; i < sz; i++) {
                auto it = q.front();
                q.pop();
                int x = it.first, y = it.second;

                for (int z = 0; z < 4; z++) {
                    int nx = x + dx[z], ny = y + dy[z];
                    if(!isSafe(nx, ny)) continue;
                    if (matrix[nx][ny] <= matrix[x][y]) continue;
                    indegree[nx][ny]--;
                    if(indegree[nx][ny] == 0) {
                        q.push({nx, ny});
                    }
                }
            }
            level++;
        }
        return level;
    }
    
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        n = matrix.size(), m = matrix[0].size();
        indegree = vector<vector<int>>(n, vector<int>(m, 0));

        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                for (int z = 0; z < 4; z++) {
                    int ni = i + dx[z], nj = j + dy[z];
                    if(!isSafe(ni, nj)) continue;
                    if (matrix[ni][nj] <= matrix[i][j]) continue;
                    indegree[ni][nj]++;
                }
            }
        }
        return kahn(matrix);
    }
};
