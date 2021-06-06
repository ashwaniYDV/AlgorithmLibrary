// https://leetcode.com/problems/kth-smallest-element-in-a-sorted-matrix/

/*
Given an n x n matrix where each of the rows and columns are sorted in ascending order, return the kth smallest element in the matrix.
Note that it is the kth smallest element in the sorted order, not the kth distinct element.
*/

class Solution {
public:
    // count no of elements less than or equal to target in row-column wise sorted matrix
    int countNoOfEleUptoTarget(vector<vector<int>> &mat, int target) {
        int n = mat.size(), m = mat[0].size();
        int i = n-1, j = 0, cnt = 0;
        while(i >= 0 && j < m) {
            if(mat[i][j] <= target) {
                cnt += i + 1;
                j++;
            } else {
                i--;
            }
        }
        return cnt;
    }
    
    int kthSmallest(vector<vector<int>>& mat, int k) {
        int n = mat.size();
        int lb = mat[0][0], ub = mat[n-1][n-1];
        
        while(lb < ub) {
            int mid = lb + (ub - lb) / 2;
            int cnt = countNoOfEleUptoTarget(mat, mid);
            if(cnt >= k)
                ub = mid;
            else
                lb = mid + 1;
        }
        return ub;
    }
};
