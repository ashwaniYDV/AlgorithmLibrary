// https://www.lintcode.com/problem/139/
// https://www.geeksforgeeks.org/find-sub-array-sum-closest-0/

/*
Given an integer array, find a subarray with sum closest to zero.
Return the indexes of the first number and last number.
Return any valid answer.

It is guaranteed that the sum of any numbers is in [-2^{31},2^{31}-1]

Example 1:
Input: [-3,1,1,-3,5] 
Output: [0, 2]
Other valid answers: [0,2], [1,3], [1,1], [2,2], [0,4]

Expected O(nlogn) time.
*/



/*
a) Maintain a Prefix sum array. Also maintain indexes in the prefix sum array.
b) Sort the prefix sum array on the basis of sum.
c) Find the two elements in a prefix sum array with minimum difference. 
 
i.e.  Find min(pre_sum[i] - pre_sum[i-1]) 

d) Return indexes of pre_sum with minimum difference.
e) Subarray with (lower_index+1, upper_index) will have the sum closest to 0.

Taking lower_index+1 because on subtracting value at lower_index we get the sum closest to 0. That’s why lower_index need not to be included.
*/



class Solution {
public:
    /*
     * @param nums: A list of integers
     * @return: A list of integers includes the index of the first number and the index of the last number
     */
    
    vector<int> subarraySumClosest(vector<int> &nums) {
        int n = nums.size();
        int min_diff = INT_MAX, left = -1, right = -1;
    
        vector<pair<int, int>> pref_sum;
    
        // To consider the case of subarray starting from beginning of the array
        pref_sum.push_back({0, -1});
    
        int sum = 0;
        // Store prefix sum with index
        for (int i = 0; i < n; i++) {
            sum += nums[i];
            pref_sum.push_back({sum, i});
        }
    
        // Sort on the basis of pref sum
        sort(pref_sum.begin(), pref_sum.end());

    
        // Find two consecutive elements with minimum difference
        for (int i = 0; i < pref_sum.size() - 1; i++) {
            int diff = pref_sum[i+1].first - pref_sum[i].first;
    
            if (min_diff > diff) {
                min_diff = diff;
                left = min(pref_sum[i].second, pref_sum[i+1].second);
                right = max(pref_sum[i].second, pref_sum[i+1].second);
            }
        }

        if(left == -1 && right == -1) return {0, 0};
        return {left + 1, right};
    }
};
