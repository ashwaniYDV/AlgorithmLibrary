// https://leetcode.com/problems/find-k-pairs-with-smallest-sums/
// https://leetcode.com/problems/find-k-pairs-with-smallest-sums/discuss/84551/simple-Java-O(KlogK)-solution-with-explanation

/*
Problem:
You are given two integer arrays nums1 and nums2 sorted in ascending order and an integer k.
Define a pair (u, v) which consists of one element from the first array and one element from the second array.
Return the k pairs (u1, v1), (u2, v2), ..., (uk, vk) with the smallest sums.
*/

/*
Basic idea: Use min_heap to keep track on next minimum pair sum, 
and we only need to maintain K possible candidates in the data structure.

Some observations: 
i) For every numbers in nums1, its best partner (yields min sum) always strats from nums2[0] since arrays are all sorted.
ii) And for a specific number in nums1, its next candidate sould be [this specific number] + nums2[current_index + 1]
*/

class Solution {
public:
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        int n1 = nums1.size(), n2 = nums2.size();
        
        vector<vector<int>> res;
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
            res.push_back({nums1[i], nums2[j]});
            
            // very important part in whole solN
            if(j == 0 && i+1 < n1)
                pq.push({nums1[i+1] + nums2[j],i+1, j});
            
            if(i < n1 && j+1 < n2)
                pq.push({nums1[i] + nums2[j+1], i, j+1});
        }
        return res;
    }
};
