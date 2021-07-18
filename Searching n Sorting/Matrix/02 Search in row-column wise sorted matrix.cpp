// https://leetcode.com/problems/search-a-2d-matrix-ii/
// https://youtu.be/9ZbB397jU4k?si=5g11nqazs0t_HWad

/*
Given a matrix mat[][] where every row and column is sorted in increasing order.
Integers in each row are sorted in ascending from left to right.
Integers in each column are sorted in ascending from top to bottom.
Find whether element target is present in the matrix or not.

Note: 
======
* We cannot apply binary search concept of "Search in fully sorted matrix" in row wise and column wise sorted matrix.
* Because in row and column wise sorted matrix, this condition may not hold => "First element of each row is > last element of previous row"

Example:
    10 20 30 40 
    15 25 35 45 
    27 29 37 48 
    32 33 39 50

    40 = last element of 1st row
    15 = first element of 2nd row

    If we write this array in 1D form:
    10 20 30 40 15 25 35 45 27 29 37 48 32 33 39 50
             ========
    These elements are not sorted.
*/


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

