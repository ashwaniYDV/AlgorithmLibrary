// https://leetcode.com/problems/kth-smallest-element-in-a-sorted-matrix/

/*
Problem:
Given an n x n matrix where each of the rows and columns are sorted in ascending order, return the kth smallest element in the matrix.
Note that it is the kth smallest element in the sorted order, not the kth distinct element.
*/


/* 
Method 1: Using Heap
Time Complexity:- O(NlogN)
Space Complexity:- O(N)
*/

/*
Here, we know that the row and column is already sorted. 
Therefore, instead of traversing in the entire matrix we can take advantage of that. 
We can take a Min Heap and push the First row(value, indexes) into Min heap. 
You can push first column also, and write your answer according to that.

Now,follow these steps:-

Pop the element from min heap and check whether it is the Kth smallest element. If it is return the value.
Else push the next row value (Note:- column is going to remain same).
The reason behind this logic is, 
when we remove the smallest element from Min Heap (i.e our 1st smallest element, which is always present in the 1st row and 1st column), 
then the 2nd smallest element may lie in that 2nd row and 1st column or it may be present in the First Row and column greater than 1.
*/

class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        priority_queue<vector<int>, vector<vector<int>> , greater<vector<int>>> pq;
        int n = matrix.size(), m = matrix[0].size();
        for(int j = 0; j < m; j++)
            pq.push({matrix[0][j], 0, j});
        
        int res;
        while(k--) {
            int val = pq.top()[0];
            int i = pq.top()[1];
            int j = pq.top()[2];
            pq.pop();
            res = val;
            
            if(i+1 < n) {
                pq.push({matrix[i + 1][j], i + 1, j});
            }
        }
        return res;
    }
};



/*
Method 2: Using Binary Search
Time Complexity:- O(NlogN)
Space Complexity:- O(1)
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
