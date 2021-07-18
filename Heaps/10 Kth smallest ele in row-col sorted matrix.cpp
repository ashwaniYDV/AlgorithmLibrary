// https://leetcode.com/problems/kth-smallest-element-in-a-sorted-matrix/

/*
Given an n x n matrix where each of the rows and columns are sorted in ascending order, 
return the kth smallest element in the matrix.
Note that it is the kth smallest element in the sorted order, not the kth distinct element.
*/



/* 
Method 1: Using Heap
Time Complexity:- O(NlogN)
Space Complexity:- O(N)

Here, we know that the row and column is already sorted. 
Therefore, instead of traversing in the entire matrix we can take advantage of that. 
We can take a Min Heap and push the First column(value, indexes) into Min heap. 
You can push first row also, and write your answer according to that.
*/

// Method 2
class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        priority_queue<array<int, 3>, vector<array<int, 3>> , greater<array<int, 3>>> pq;
        int n = matrix.size(), m = matrix[0].size();
        
        for (int i = 0; i < n; i++) {
            pq.push({matrix[i][0], i, 0});
        }

        int res;
        while (k--) {
            int val = pq.top()[0];
            int i = pq.top()[1];
            int j = pq.top()[2];
            pq.pop();
            res = val;

            if (j + 1 < m) {
                pq.push({matrix[i][j + 1], i, j + 1});
            }
        }
        return res;
    }
};









/* 
Method 1: Using BS
Time Complexity:- O(NlogN)
Space Complexity:- O(1)
*/

// FFFFFFTTTTTTTT

class Solution {
public:
    // count no of elements less than or equal to target in row-column wise sorted matrix
    int countNoOfEleUptoTarget(vector<vector<int>> &mat, int target) {
        int n = mat.size(), m = mat[0].size();
        int i = 0, j = m - 1, cnt = 0;
        while (i < n && j >= 0) {
            if (mat[i][j] <= target) {
                cnt += j + 1;
                i++;
            } else {
                j--;
            }
        }
        return cnt;
    }

    int kthSmallest(vector<vector<int>>& mat, int k) {
        int n = mat.size();
        int lo = mat[0][0], hi = mat[n - 1][n - 1];

        while (lo < hi) {
            int mid = lo + (hi - lo) / 2;
            int cnt = countNoOfEleUptoTarget(mat, mid);
            if (cnt >= k)
                hi = mid;
            else
                lo = mid + 1;
        }
        return lo;
    }
};
