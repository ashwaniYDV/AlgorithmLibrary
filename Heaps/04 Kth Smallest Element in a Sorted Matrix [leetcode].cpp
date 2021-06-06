// https://leetcode.com/problems/kth-smallest-element-in-a-sorted-matrix/

/*
Problem:
Given an n x n matrix where each of the rows and columns are sorted in ascending order, return the kth smallest element in the matrix.
Note that it is the kth smallest element in the sorted order, not the kth distinct element.
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
