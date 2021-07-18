// https://leetcode.com/problems/find-a-peak-element-ii/
// https://youtu.be/nGGp5XBzC4g?si=16DUb4GDfbiIFwm8

/*
A peak element in a 2D grid is an element that is 
strictly greater than all of its adjacent neighbors in all 4 directions.
Given a 0-indexed m x n matrix mat where no two adjacent cells are equal, 
find any peak element mat[i][j] and return the length 2 array [i,j].
You may assume that the entire matrix is surrounded by an outer perimeter with the value -1 in each cell.
You must write an algorithm that runs in O(m log(n)) or O(n log(m)) time.
*/

/*
Read my intuition:
https://leetcode.com/problems/find-a-peak-element-ii/solutions/4972330/c-detailed-explanation-with-intuition-approach-and-drawing-parallels-with-1d-peak-element-que/
*/

class Solution {
    public: vector < int > findPeakGrid(vector < vector < int >> & mat) {
        int n = mat.size(), m = mat[0].size();

        // low = 1st column, high = last column
        int loCol = 0, hiCol = m - 1;

        while (loCol <= hiCol) {
            int midCol = (loCol + hiCol) >> 1;

            // Find row index of maximum element in midCol 
            int maxRow = 0;
            for (int i = 0; i < n; i++) {
                if (mat[i][midCol] > mat[maxRow][midCol]) {
                    maxRow = i;
                }
            }

            int currElement = mat[maxRow][midCol];
            int leftElement = (midCol == 0) ? -1 : mat[maxRow][midCol - 1];
            int rightElement = (midCol == m - 1) ? -1 : mat[maxRow][midCol + 1];

            // we only have to check if current element is strictly greater than its left and right elements
            // since current element in greatest in its column, so it will be strictly greater than its top and bottom elements
            if (currElement > leftElement && currElement > rightElement) {
                return { maxRow, midCol };
            }

            // similar concept of 1D problem
            // answer lies in left part
            if (leftElement > currElement) {
                hiCol = midCol - 1;
            } 
            // answer lies in right part
            else {
                loCol = midCol + 1;
            }
        }
        
        return {-1, -1};
    }
};