/*
You are given an integer array nums of length n and a 2D array queries where queries[i] = [li, ri, vali].
Each queries[i] represents the following action on nums:
* Decrement the value at each index in the range [li, ri] in nums by at most vali.
* The amount by which each value is decremented can be chosen independently for each index.
A Zero Array is an array with all its elements equal to 0.
Return the minimum possible non-negative value of k, such that after processing the first k queries in sequence, nums becomes a Zero Array. If no such k exists, return -1.

 
Input: nums = [2,0,2], queries = [[0,2,1],[0,2,1],[1,1,3]]
Output: 2
Explanation:
For i = 0 (l = 0, r = 2, val = 1):
Decrement values at indices [0, 1, 2] by [1, 0, 1] respectively.
The array will become [1, 0, 1].
For i = 1 (l = 0, r = 2, val = 1):
Decrement values at indices [0, 1, 2] by [1, 0, 1] respectively.
The array will become [0, 0, 0], which is a Zero Array. Therefore, the minimum value of k is 2.

Input: nums = [4,3,2,1], queries = [[1,3,2],[0,2,1]]
Output: -1
Explanation:
For i = 0 (l = 1, r = 3, val = 2):
Decrement values at indices [1, 2, 3] by [2, 2, 1] respectively.
The array will become [4, 1, 0, 0].
For i = 1 (l = 0, r = 2, val = 1):
Decrement values at indices [0, 1, 2] by [1, 1, 0] respectively.
The array will become [3, 0, 0, 0], which is not a Zero Array.
 

Constraints:
1 <= nums.length <= 10^5
0 <= nums[i] <= 5 * 10^5
1 <= queries.length <= 10^5
queries[i].length == 3
0 <= li <= ri < nums.length
1 <= vali <= 5
*/


class Solution {
public:
    bool check(int mid, vector<int>& a, vector<vector<int>>& queries) {
        int n = a.size();
        vector<int> maxDeletions(n+1, 0);

        for(int i = 0; i < mid; i++) {
            auto it = queries[i];
            int l = it[0], r = it[1], val = it[2];
            maxDeletions[l] += val;
            maxDeletions[r+1] -= val;
        }

        // pref sum
        for(int i = 1; i < n+1; i++) {
            maxDeletions[i] += maxDeletions[i - 1];
        }

        for(int i = 0; i < n; i++) {
            // we cannot make it zero by nax deletions
            if(a[i] > maxDeletions[i]) return false;
        }

        return true;
    }

    // FFFFFTTTTTT
    int minZeroArray(vector<int>& a, vector<vector<int>>& queries) {
        int lo = 0, hi = queries.size();
        while(lo <= hi) {
            int mid = (lo + hi) / 2;
            if(check(mid, a, queries)) {
                hi = mid - 1;
            } else {
                lo = mid + 1;
            }
        }
        return lo > queries.size() ? -1 : lo;
    }
};
