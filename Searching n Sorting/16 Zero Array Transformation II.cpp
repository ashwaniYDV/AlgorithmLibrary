// https://leetcode.com/problems/zero-array-transformation-ii/

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












// https://leetcode.com/problems/zero-array-transformation-i/

/*
You are given an integer array nums of length n and a 2D array queries, where queries[i] = [li, ri].
For each queries[i]:
* Select a subset of indices within the range [li, ri] in nums.
* Decrement the values at the selected indices by 1.
A Zero Array is an array where all elements are equal to 0.
Return true if it is possible to transform nums into a Zero Array after processing all the queries sequentially, otherwise return false.


Input: nums = [1,0,1], queries = [[0,2]]
Output: true
Explanation:
For i = 0:
Select the subset of indices as [0, 2] and decrement the values at these indices by 1.
The array will become [0, 0, 0], which is a Zero Array.

Constraints:
1 <= nums.length <= 10^5
0 <= nums[i] <= 10^5
1 <= queries.length <= 10^5
queries[i].length == 2
0 <= li <= ri < nums.length
*/

class Solution {
public:
    bool isZeroArray(vector<int>& a, vector<vector<int>>& queries) {
        int n = a.size();
        vector<int> maxDeletions(n+1, 0);

        for(auto& it: queries) {
            int l = it[0], r = it[1];
            maxDeletions[l] += 1;
            maxDeletions[r+1] -= 1;
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
};
