// https://www.lintcode.com/problem/434/description

/*
Given a 2D matrix of size n * m and an array of pair of size K. 
Originally, the 2D matrix is all 0 which means there is only sea in the matrix. 
The list pair has k operator and each operator has two integer A[i].x, A[i].y means that you can change the grid[A[i].x][A[i].y] from sea to island. 
Return how many island are there in the matrix after each operator.
You need to return an array of size K.


Input: n = 4, m = 5, A = [[1,1],[0,1],[3,3],[3,4]]
Output: [1,1,2,2]
Explanation:
0.  00000
    00000
    00000
    00000
1.  00000
    01000
    00000
    00000
2.  01000
    01000
    00000
    00000
3.  01000
    01000
    00000
    00010
4.  01000
    01000
    00000
    00011
*/


/**
 * Definition for a point.
 * struct Point {
 *     int x;
 *     int y;
 *     Point() : x(0), y(0) {}
 *     Point(int a, int b) : x(a), y(b) {}
 * };
 */

class Solution {
public:
    /**
     * @param n: An integer
     * @param m: An integer
     * @param operators: an array of point
     * @return: an integer array
     */
    int dx[4] = {0, 1, 0, -1};
    int dy[4] = { -1, 0, 1, 0};

    bool isSafe(int i, int j, int n, int m, vector<vector<int>>& g) {
        if(i < 0 || i >= n || j < 0 || j >= m || g[i][j] == 0)
            return false;
        return true;
    }

    struct DSU {
        vector<int> par;
        void init(int n) {
            par.resize(n+1, -1);
        }
        int findParent(int a) {
            if(par[a] < 0) return a;
            return par[a] = findParent(par[a]);
        }
        bool unionSet(int a, int b) {
            a = findParent(a);
            b = findParent(b);
            if(a == b) return 0;
            if(par[a] > par[b]) swap(a, b);
            par[a] += par[b];
            par[b] = a;
            return 1;
        }
        bool sameSet(int x, int y) { 
            return findParent(x) == findParent(y); 
        }
        int size (int x) { 
            return -par[findParent(x)]; 
        }
    };

    vector<int> numIslands2(int n, int m, vector<Point> &operators) {
        DSU dsu;
        dsu.init(n * m);

        vector<vector<int>> g(n, vector<int>(m, 0));
        vector<int> res;
        int islands = 0;

        for(auto it: operators) {
            int x = it.x, y = it.y;

            // it is already land
            if(g[x][y] == 1) {
                res.push_back(islands);
                continue;
            }

            for(int z = 0; z < 4; z++) {
                int n_x = x + dx[z], n_y = y + dy[z];
                if(!isSafe(n_x, n_y, n, m, g)) continue;

                int idx1 = x * m + y;
                int idx2 = n_x * m + n_y;
                if(!dsu.sameSet(idx1, idx2)) {
                    islands--;
                    dsu.unionSet(idx1, idx2);
                }
            }

            islands++;
            res.push_back(islands);
            g[x][y] = 1;
        }

        return res;
    }
};
