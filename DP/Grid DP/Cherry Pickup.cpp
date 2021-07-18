// https://leetcode.com/problems/cherry-pickup/
// https://youtu.be/ZV0sUzfA7Eg

/*
You are given an n x n grid representing a field of cherries, each cell is one of three possible integers.
a) 0 means the cell is empty, so you can pass through,
b) 1 means the cell contains a cherry that you can pick up and pass through, or
c) -1 means the cell contains a thorn that blocks your way.
Return the maximum number of cherries you can collect by following the rules below:
a) Starting at the position (0, 0) and reaching (n - 1, n - 1) by moving right or down through valid path cells (cells with value 0 or 1).
b) After reaching (n - 1, n - 1), returning to (0, 0) by moving left or up through valid path cells.
c) When passing through a path cell containing a cherry, you pick it up, and the cell becomes an empty cell 0.
d) If there is no valid path between (0, 0) and (n - 1, n - 1), then no cherries can be collected.
*/



/*
DP Solution O(n^4) memory:
Instead of sending a person down and then reversing it's direction to up. 
What we are doing here is we are hypothetically sending 2 person down.
So if they land on same cherry grid[i][j] we will add only one cherry, 
and if they land on 2 different grids we will add two cherries corresponding to the grids.
Since there are 2 person thus total 4 moves are possible:
Person1->Right && Person2->Right
Person1->Right && Person2->Down
Person1->Down && Person2->Right
Person1->Down && Person2->Down
*/ 
class Solution {
public:
    int n;
    int dp[51][51][51][51];
    
    int go(int i1, int j1, int i2, int j2, vector<vector<int>>& grid) {
        if(i1 < 0 || i1 >= n || j1 < 0 || j1 >= n || grid[i1][j1] == -1) return INT_MIN;
        if(i2 < 0 || i2 >= n || j2 < 0 || j2 >= n || grid[i2][j2] == -1) return INT_MIN;
        
        // here i1 == n - 1 && j1 == n - 1 && i2 == n - 1 && j2 == n - 1 (since they have moved same number of steps)
        if(i1 == n - 1 && j1 == n - 1) {
            return grid[i1][j1];
        }
        
        if(dp[i1][j1][i2][j2] != -1) return dp[i1][j1][i2][j2];
        
        int cherries = 0;
        
        if(i1 == i2 && j1 == j2) {
            cherries += grid[i1][j1];
        } else {
            cherries += grid[i1][j1] + grid[i2][j2];
        }
        
        int res1 = go(i1 + 1, j1, i2 + 1, j2, grid);
        int res2 = go(i1 + 1, j1, i2, j2 + 1, grid);
        int res3 = go(i1, j1 + 1, i2 + 1, j2, grid);
        int res4 = go(i1, j1 + 1, i2, j2 + 1, grid);
        
        return dp[i1][j1][i2][j2] = cherries + max({res1, res2, res3, res4});
    }
    
    int cherryPickup(vector<vector<int>>& grid) {
        n = grid.size();
        memset(dp, -1, sizeof dp);
        return max(0, go(0, 0, 0, 0, grid));
    }
};





/*
DP Solution O(n^3) memory:
Same as above DP solution with one space optimization, using the fact:
i1 + j1 = i2 + j2 (Since both persons move same number of steps)
Thus, 
j2 = i1 + j1 - i2
*/ 
class Solution {
public:
    int n;
    int dp[51][51][51];
    
    int go(int i1, int j1, int i2, vector<vector<int>>& grid) {
        int j2 = i1 + j1 - i2;
        
        if(i1 < 0 || i1 >= n || j1 < 0 || j1 >= n || grid[i1][j1] == -1) return INT_MIN;
        if(i2 < 0 || i2 >= n || j2 < 0 || j2 >= n || grid[i2][j2] == -1) return INT_MIN;
        
        if(i1 == n - 1 && j1 == n - 1) {
            return grid[i1][j1];
        }
        
        if(dp[i1][j1][i2] != -1) return dp[i1][j1][i2];
        
        int cherries = 0;
        
        if(i1 == i2 && j1 == j2) {
            cherries += grid[i1][j1];
        } else {
            cherries += grid[i1][j1] + grid[i2][j2];
        }
        
        // int res1 = go(i1 + 1, j1, i2 + 1, j2, grid);
        // int res2 = go(i1 + 1, j1, i2, j2 + 1, grid);
        // int res3 = go(i1, j1 + 1, i2 + 1, j2, grid);
        // int res4 = go(i1, j1 + 1, i2, j2 + 1, grid);
        int res1 = go(i1 + 1, j1, i2 + 1, grid);
        int res2 = go(i1 + 1, j1, i2, grid);
        int res3 = go(i1, j1 + 1, i2 + 1, grid);
        int res4 = go(i1, j1 + 1, i2, grid);
        
        return dp[i1][j1][i2] = cherries + max({res1, res2, res3, res4});
    }
    
    int cherryPickup(vector<vector<int>>& grid) {
        n = grid.size();
        memset(dp, -1, sizeof dp);
        return max(0, go(0, 0, 0, grid));
    }
};




// Bottom Up
class Solution {
public:    
    int cherryPickup(vector<vector<int>>& grid) {
        int n = grid.size();
        int dp[n+1][n+1][n+1];
        
        for(int i = 0; i <= n; i++) {
            for(int j = 0; j <= n; j++) {
                for(int k = 0; k <= n; k++) {
                    dp[i][j][k] = INT_MIN;
                }
            }
        }
        
        dp[1][1][1] = grid[0][0];
        
        for(int x1 = 1; x1 <= n; x1++) {
            for(int y1 = 1; y1 <= n; y1++) {
                for(int x2 = 1; x2 <= n; x2++) {
                    int y2 = x1 + y1 - x2;
                    
                    // have already detected
                    if(dp[x1][y1][x2] > 0) {
                        continue;
                    }
                    // out of boundary
                    if(y2 < 1 || y2 > n) {
                        continue;
                    }
                    // cannot access 
                    if(grid[x1 - 1][y1 - 1] == -1 || grid[x2 - 1][y2 - 1] == -1) {
                        continue;
                    }
                    
                    int cur = max({dp[x1 - 1][y1][x2], dp[x1 - 1][y1][x2 - 1], dp[x1][y1 - 1][x2], dp[x1][y1 - 1][x2 - 1]});
                    if(cur < 0) {
                        continue;
                    }
                    
                    int cherries = 0;
                    if(x1 == x2 && y1 == y2) {
                        cherries = grid[x1 - 1][y1 - 1];
                    } else {
                        cherries = grid[x1 - 1][y1 - 1] + grid[x2 - 1][y2 - 1];
                    }
                    
                    dp[x1][y1][x2] = cherries + cur;
                }
            }
        }
        
        return dp[n][n][n] < 0 ? 0 : dp[n][n][n];
    }
};






























// TLE Backtracking solution
class Solution {
public:
    int n;
    
    int go(int i, int j, int isBackTrip, vector<vector<int>>& grid) {
        if(isBackTrip) {
            if(grid[i][j] == -1) return INT_MIN;
            
            if(i == 0 && j == 0) {
                return grid[i][j];
            }
            
            int cherry = grid[i][j], res;
            // marked as visited by picking a cherry if any
            grid[i][j] = 0;
            
            if(i == 0) {
                res = cherry + go(i, j - 1, 1, grid);
            }
            else if(j == 0) {
                res = cherry + go(i - 1, j, 1, grid);
            } 
            else {
                res = cherry + max(go(i - 1, j, 1, grid), go(i, j - 1, 1, grid));
            }
            
            // backtracking
            grid[i][j] = cherry;
            
            return res;
        } else {
            if(grid[i][j] == -1) return INT_MIN;
            
            int cherry = grid[i][j], res, x = 0, y = 0;
            // marked as visited by picking a cherry if any
            grid[i][j] = 0;
            
            if(i == n - 1 && j == n - 1) {
                // res = cherry + max(go(i - 1, j, 1, grid), go(i, j - 1, 1, grid));
                
                // handle case when grid = [[1]] (i.e n = 1, m = 1)
                if(i - 1 >= 0) {
                    x = cherry + go(i - 1, j, 1, grid);
                }
                if(j - 1 >= 0) {
                    y = cherry + go(i, j - 1, 1, grid);
                }
                res = max({cherry, x, y});
            }
            
            else if(i == n - 1) {
                res = cherry + go(i, j + 1, 0, grid);
            }
            else if(j == n - 1) {
                res = cherry + go(i + 1, j, 0, grid);
            }
            else {
                res = cherry + max(go(i + 1, j, 0, grid), go(i, j + 1, 0, grid));
            }
            
            // backtracking
            grid[i][j] = cherry;
            
            return res;
        }
    }
    
    int cherryPickup(vector<vector<int>>& grid) {
        n = grid.size();
        int res = go(0, 0, 0, grid);
        return max(0, res);
    }
};





// TLE Backtracking solution
class Solution {
public:
    int n, res;
    
    void backTrip(int i, int j, int total, vector<vector<int>>& grid) {
        if(i < 0 || i >= n || j < 0 || j >= n || grid[i][j] == -1) return;
        
        if(i == 0 && j == 0) {
            res = max(res, total);
            return;
        }
        
        int cherry = grid[i][j];
        grid[i][j] = 0;
        backTrip(i - 1, j, total + cherry, grid);
        backTrip(i, j - 1, total + cherry, grid);
        grid[i][j] = cherry;
    }
    
    void go(int i, int j, int total, vector<vector<int>>& grid) {
        if(i < 0 || i >= n || j < 0 || j >= n || grid[i][j] == -1) return;
        
        if(i == n - 1 && j == n - 1) {
            res = max(res, total + grid[i][j]);
            backTrip(i, j, total, grid);
            return;
        }
        
        int cherry = grid[i][j];
        grid[i][j] = 0;
        go(i + 1, j, total + cherry, grid);
        go(i, j + 1, total + cherry, grid);
        grid[i][j] = cherry;
    }
    
    int cherryPickup(vector<vector<int>>& grid) {
        n = grid.size();
        res = 0;
        go(0, 0, 0, grid);
        return res;
    }
};
