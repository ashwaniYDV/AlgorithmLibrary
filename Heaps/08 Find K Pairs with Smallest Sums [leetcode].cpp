// https://leetcode.com/problems/find-k-pairs-with-smallest-sums/
// https://leetcode.com/problems/find-k-pairs-with-smallest-sums/discuss/84551/simple-Java-O(KlogK)-solution-with-explanation

/*
Problem:
You are given two integer arrays nums1 and nums2 sorted in ascending order and an integer k.
Define a pair (u, v) which consists of one element from the first array and one element from the second array.
Return the k pairs (u1, v1), (u2, v2), ..., (uk, vk) with the smallest sums.

Input: nums1 = [1,7,11], nums2 = [2,4,6], k = 3
Output: [[1,2],[1,4],[1,6]]
Explanation: The first 3 pairs are returned from the sequence: [1,2],[1,4],[1,6],[7,2],[7,4],[11,2],[7,6],[11,4],[11,6]
*/

/*
Intuition
=========
* There will be total n1 * n2 pair sums
* Use min_heap to keep track on next minimum pair sum, and we only need to maintain K possible candidates in the data structure.

Think with respect to i variable and not both i, j variables

Some observations: 
i) For every numbers in nums1, its best partner (yields min sum) always strats from nums2[0] since arrays are all sorted.
ii) And for a specific number in nums1, its next candidate sould be [this specific number] + nums2[current_index + 1]

The run time complexity is O(kLogk) since que.size <= k and we do at most k loop.
The above solution is essentially a multiple-way merge sort
*/


// Method 1: (TLE)
/*
Form all those n1*n2 pairs and sort them. Finally return first k pairs.
*/



// Method 2.1: (Using min heap, Time = k*logk)
class Solution {
public:
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        int n1 = nums1.size(), n2 = nums2.size();
        vector<vector<int>> res;
        if (!n1 || !n2) return res;

        // minheap {nums[i] + nums2[j], i, j}
        priority_queue <array<int, 3>, vector<array<int, 3>>, greater<array<int, 3>>> pq;

        for (int i = 0; i < n1; i++) {
            pq.push({nums1[i] + nums2[0], i, 0});
        }
        
        while (!pq.empty() && k--) {
            auto it = pq.top();
            pq.pop();
            int i = it[1];
            int j = it[2];

            res.push_back({nums1[i], nums2[j]});
            
            if (j + 1 < n2) {
                pq.push({nums1[i] + nums2[j + 1], i, j + 1});
            }
        }
        return res;
    }
};



// Method 2.2: (Using custom comparator)
class Solution {
public:
    struct comparator {
        bool operator() (array<int, 3>& a, array<int, 3>& b) {
            // Note: comparision is reverse of what we do to sort vectors
            return !(a[0] < b[0]);
        }
    };
    
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        int n1 = nums1.size(), n2 = nums2.size();
        vector<vector<int>> res;
        if (!n1 || !n2) return res;

        // minheap {nums[i] + nums2[j], i, j}
        priority_queue<array<int, 3>, vector<array<int, 3>>, comparator> pq;

        for (int i = 0; i < n1; i++) {
            pq.push({nums1[i] + nums2[0], i, 0});
        }
        
        while (!pq.empty() && k--) {
            auto it = pq.top();
            pq.pop();
            int i = it[1];
            int j = it[2];

            res.push_back({nums1[i], nums2[j]});
            
            if (j + 1 < n2) {
                pq.push({nums1[i] + nums2[j + 1], i, j + 1});
            }
        }
        return res;
    }
};