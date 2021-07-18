// https://leetcode.com/problems/search-a-2d-matrix/

/*
Write an efficient algorithm that searches for a value in an m x n matrix. 
This matrix has the following properties:
a) Integers in each row are sorted from left to right.
b) First element of each row is > last element of previous row. [* This condition is necessary to apply binary search in whole matrx]

Input: 
matrix = [[1,3,5,7],
          [10,11,16,20],
          [23,30,34,60]], 
target = 3
Output: true


Note:
=====
* According to given constraints, if we push all the elements in a 1-D vector then all the elements will be sorted.
* But this condition does not hold true, if question was for row wise and column wise sorted array.
Example:
    10 20 30 40 
    15 25 35 45 
    27 29 37 48 
    32 33 39 50

    If we write this array in 1D form:
    10 20 30 40 15 25 35 45 27 29 37 48 32 33 39 50
             ========
    These elements are not sorted.
*/

// Method 1
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n = matrix.size(), m = matrix[0].size();

        int lo = 0, hi = n * m - 1;

        while (lo <= hi) {
            int mid = lo + (hi - lo) / 2;
            int x = mid / m, y = mid % m;

            if (matrix[x][y] == target) return true;

            if (target > matrix[x][y]) {
                lo = mid + 1;
            } else {
                hi = mid - 1;
            }
        }

        return false;
    }
};



// Method 2
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n = matrix.size(), m = matrix[0].size();
        if(target < matrix[0][0] || target > matrix[n-1][m-1]) {
            return 0;
        }
    
        int i = 0, j = m-1;
    
        while(i < n && j >= 0) {
            if(matrix[i][j] == target) {
                return 1;
            }
            if(target > matrix[i][j]) {
                i++;
            } else {
                j--;
            }
        }
        
        return 0;
    }
};