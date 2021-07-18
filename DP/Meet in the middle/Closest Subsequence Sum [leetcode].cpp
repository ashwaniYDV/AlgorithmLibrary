// https://leetcode.com/problems/closest-subsequence-sum/

/*
You are given an integer array nums and an integer goal.
You want to choose a subsequence of nums such that the sum of its elements is the closest possible to goal. 
That is, if the sum of the subsequence's elements is sum, then you want to minimize the absolute difference abs(sum - goal).
Return the minimum possible value of abs(sum - goal).
Note that a subsequence of an array is an array formed by removing some elements (possibly all or none) of the original array.

Example 1:
Input: nums = [5,-7,3,5], goal = 6
Output: 0
Explanation: Choose the whole array as a subsequence, with a sum of 6.

Example 2:
Input: nums = [7,-9,15,-2], goal = -5
Output: 1
Explanation: Choose the subsequence [7,-9,-2], with a sum of -4.


Constraints:
1 <= nums.length <= 40
-10^7 <= nums[i] <= 10^7
-10^9 <= goal <= 10^9
*/


/*
Algorithm (Meet in the middle):
a) Divide the search space into two parts of more or less equal sizes (part1 and part2).
b) Find all possible subset sums of both parts separately (subsetSum1 and subsetSum2).
c) Sort the set of subset sums so that we can perform 2 pointer technique for closets sum.
*/

// Time = O(n * 2^(n / 2))
class Solution {
public:
    vector<int> getSubsetSumsHelper(vector<int> a) {
        int n = a.size();
        vector<int> subsetSum;
        for(int mask = 0; mask < (1 << n); mask++) {
            int sum = 0;
            for(int i = 0; i < n; i++) {
                if((mask & (1 << i))) sum += a[i];
            }
            subsetSum.push_back(sum);
        }
        return subsetSum;
    }

    int minAbsDifference(vector<int>& nums, int goal) {
        int n = nums.size();
        vector<int> a1, a2;
        for(int i = 0; i < n; i++) {
            if(i < (n / 2)) 
                a1.push_back(nums[i]);
            else 
                a2.push_back(nums[i]);
        }

        vector<int> subsetSum1 = getSubsetSumsHelper(a1);
        vector<int> subsetSum2 = getSubsetSumsHelper(a2);

        sort(subsetSum1.begin(), subsetSum1.end());
        sort(subsetSum2.begin(), subsetSum2.end());

        int res = abs(goal);

        int i1 = 0, i2 = subsetSum2.size() - 1;
        while(i1 < subsetSum1.size() && i2 >= 0) {
            int cur = subsetSum1[i1] + subsetSum2[i2];
            res = min(res, abs(cur - goal));
            if (cur == goal)
                return 0;
            else if (cur > goal)
                i2--;
            else
                i1++;
        }

        return res;
    }
};
