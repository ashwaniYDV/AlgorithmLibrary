// https://leetcode.com/problems/count-negative-numbers-in-a-sorted-matrix/description/

/*
Given a m x n matrix grid which is sorted in non-increasing order both row-wise and column-wise, return the number of negative numbers in grid.

Example 1:
Input: grid = [[4,3,2,-1],[3,2,1,-1],[1,1,-1,-2],[-1,-1,-2,-3]]
Output: 8
Explanation: There are 8 negatives number in the matrix.

Example 2:
Input: grid = [[3,2],[1,0]]
Output: 0
 

Constraints:
m == grid.length
n == grid[i].length
1 <= m, n <= 100
-100 <= grid[i][j] <= 100

Follow up: Could you find an O(n + m) solution?
*/

// Method 1
class Solution {
public:
    int countNegatives(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        int i = n - 1, j = 0;

        int res = 0;

        while (i >= 0 && j < m) {
            if (grid[i][j] < 0) {
                res += m - j;
                i--;
            } else {
                j++;
            }
        }

        return res;
    }
};



// Method 2
class Solution {
public:
    int countNegatives(vector<vector<int>>& g) {
        int n = g.size(), m = g[0].size();

        int j = m-1;
        int res = 0;

        for(int i = 0; i < n; i++) {
            while(j - 1 >= 0 && g[i][j - 1] < 0) {
                j--;
            }
            if(g[i][j] < 0) {
                res += (m - j);
            }
        }

        return res;
    }
};
