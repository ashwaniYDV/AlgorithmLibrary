// https://leetcode.com/problems/maximum-product-subarray/

/*
Let me try to give some explanations for this solution.

Case 1: If there's no zero in the array
Then the subarray with maximum product must start with the first element or end with the last element. 
And therefore, the maximum product must be some prefix product or suffix product. 

Case 2: If there are zeros in the array
We can split the array into several smaller ones. 
That's to say, when the prefix product is 0, we start over and compute prefix profuct from the current element instead. 
And this is exactly what A[i] *= (A[i - 1]) or 1 does.
*/

// Method 1
class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size();
        int res = nums[0];
        int prefix = 0, suffix = 0;
        for (int i = 0; i < n; i++) {
            if (prefix == 0) prefix = 1;
            prefix *= nums[i];
            if (suffix == 0) suffix = 1;
            suffix *= nums[n - 1 - i];
            res = max({res, prefix, suffix});
        }
        return res;
    }
};













/*
When we are at index j:

maxp = maximum product of suffix (i, i+1, ..., j) ending at index j (i.e. including arr[j])
     = (arr[i] * arr[i+1] * ... * arr[j]), where i <= j
minp = minimum product of suffix (i, i+1, ..., j) ending at index j (i.e. including arr[j])
     = (arr[i] * arr[i+1] * ... * arr[j]), where i <= j

(last index j is included same as we do in dp LIS) 


NOTE: 
Same problem can be extended to calculate Minimum Product Subarray
*/

// Method 2
class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size();
        if (n == 0) return 0;

        // maintain two variables to store the maximum and minimum product ending at the current index
        int max_ending = nums[0], min_ending = nums[0];

        // to store the maximum product subarray found so far
        int max_so_far = nums[0];

        // traverse the given array
        for (int i = 1; i < n; i++) {
            int temp = max_ending;

            // update the maximum product ending at the current index
            max_ending = max({nums[i], nums[i] * max_ending, nums[i] * min_ending});

            // update the minimum product ending at the current index
            min_ending = min({nums[i], nums[i] * temp, nums[i] * min_ending});

            max_so_far = max(max_so_far, max_ending);
        }

        return max_so_far;
    }
};
