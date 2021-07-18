// https://leetcode.com/problems/set-matrix-zeroes/
// https://www.geeksforgeeks.org/a-boolean-matrix-question/

/*
Given an m x n integer matrix matrix, if an element is 0, set its entire row and column to 0's, and return the matrix.
You must do it in place.

Example 1:
Input: matrix = [[1,1,1],
                [1,0,1],
                [1,1,1]]
Output: [[1,0,1],
        [0,0,0],
        [1,0,1]]
*/


// Space = O(n)
/*
Method 1 (Use two temporary arrays) 
1) Create two temporary arrays row[M] and col[N]. Initialize all values of row[] and col[] as 0. 
2) Traverse the input matrix mat[M][N]. If you see an entry mat[i][j] as true, then mark row[i] and col[j] as true. 
3) Traverse the input matrix mat[M][N] again. For each entry mat[i][j], check the values of row[i] and col[j]. 
   If any of the two values (row[i] or col[j]) is true, then mark mat[i][j] as true.
*/


class Solution {
public:
    void setZeroes(vector<vector<int>>& a) {
        int n = a.size(), m = a[0].size();
        vector<bool> row(n, false), col(m, false);

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (a[i][j] == 0) {
                    row[i] = true;
                    col[j] = true;
                }
            }
        }

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (row[i] || col[j]) {
                    a[i][j] = 0;
                }
            }
        }
    }
};








// Space = O(1)
/*
This method is a space optimized version of above method 1. 
This method uses the 1st row and 1st column of the input matrix in place of the auxiliary arrays row[] and col[] of method 1. 

* But nums[0][0] is common to both row1 and col1, so we have to keep track of row1 and col1 separately.
* First take care of row-1 and column-1 and store the info about these two in two flag variables rowFlag and colFlag. 
* Once we have this info, we can use first row and first column as auxiliary arrays
  and apply method 1 for submatrix (matrix excluding first row and first column) of size (M-1)*(N-1).
1) Scan the 1st row and set a variable rowFlag to indicate whether we need to set all 1s in first row or not. 
2) Scan the 1st column and set a variable colFlag to indicate whether we need to set all 1s in first column or not. 
3) Use 1st row and 1st column as auxiliary arrays row[] and col[] respectively, 
   consider the matrix as submatrix starting from 2nd row and 2nd column and apply method 1. 
4) Finally, using rowFlag and colFlag, update 1st row and 1st column if needed.
*/

class Solution {
public:
    void setZeroes(vector<vector<int>>& a) {
        int n = a.size(), m = a[0].size();
        bool isRow1Zero = false, isCol1Zero = false;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (a[i][j] == 0) {
                    a[i][0] = 0;
                    a[0][j] = 0;
                    if (i == 0) isRow1Zero = true;
                    if (j == 0) isCol1Zero = true;
                }
            }
        }

        for (int i = 1; i < n; i++) {
            for (int j = 1; j < m; j++) {
                if (a[i][0] == 0 || a[0][j] == 0) {
                    a[i][j] = 0;
                }
            }
        }

        if (isCol1Zero) {
            for (int i = 0; i < n; i++) {
                a[i][0] = 0;
            }
        }

        if (isRow1Zero) {
            for (int j = 0; j < m; j++) {
                a[0][j] = 0;
            }
        }
    }
};
