// https://leetcode.com/problems/find-the-kth-smallest-sum-of-a-matrix-with-sorted-rows/

/*
You are given an m * n matrix, mat, and an integer k, which has its rows sorted in non-decreasing order.
You are allowed to choose exactly 1 element from each row to form an array. 
Return the Kth smallest array sum among all possible arrays.
*/

/*
To understand this problem, first look at - Find K Pairs with Smallest Sums (https://leetcode.com/problems/find-k-pairs-with-smallest-sums/)
The function kSmallestPairs can be taken directly from above problem.

So we start merging two rows at a time by using the function kSmallestPairs, m-1 times, keeping each time the size of the res at most k.
*/

class Solution {
public:
    // reused function of previous problem - Find K Pairs with Smallest Sums
    vector<int> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        int n1 = nums1.size(), n2 = nums2.size();
        
        vector<int> res;
        if(n1 == 0 || n2 == 0) return res;
        
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;
        // insert initial pair in priority queue
        pq.push({nums1[0] + nums2[0], 0, 0});
        
        // pq.size() is necessary coz k can be larger than m*n
        while(pq.size() && res.size() < k) {
            auto it = pq.top();
            pq.pop();
            int i = it[1];
            int j = it[2];
            // insert smallest pair in res vector
            res.push_back(nums1[i] + nums2[j]);
            
            // very important part in whole solN
            if(j == 0 && i+1 < n1)
                pq.push({nums1[i+1] + nums2[j],i+1, j});
            
            if(i < n1 && j+1 < n2)
                pq.push({nums1[i] + nums2[j+1], i, j+1});
        }
        return res;
    }
    
    int kthSmallest(vector<vector<int>>& mat, int k) {
        vector<int> row = mat[0];
        for (int r = 1; r < mat.size(); r++) {
            row = kSmallestPairs(row, mat[r], k);
        }
        return row[k-1];
        
    }
};
