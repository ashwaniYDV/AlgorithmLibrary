// https://www.geeksforgeeks.org/maximum-product-subarray/
// https://leetcode.com/problems/maximum-product-subarray/


// Method 1
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













// Method 2
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

class Solution {
public:
    long long maxProduct(vector<int> arr, int n) {
        // base case
        if (n == 0) {
            return 0;
        }

        // maintain two variables to store the maximum and minimum product ending at the current index
        long long max_ending = arr[0], min_ending = arr[0];

        // to store the maximum product subarray found so far
        long long max_so_far = arr[0];

        // traverse the given array
        for (int i = 1; i < n; i++) {
            long long temp = max_ending;

            // update the maximum product ending at the current index
            max_ending = max<long long>({arr[i], arr[i] * max_ending, arr[i] * min_ending});

            // update the minimum product ending at the current index
            min_ending = min<long long>({arr[i], arr[i] * temp, arr[i] * min_ending});

            max_so_far = max<long long>(max_so_far, max_ending);
        }

        // return maximum product
        return max_so_far;
    }
};













// Method 3
// Maximum Product Subarray
class Solution {
public:
    long long maxProduct(vector<int> arr, int n) {
        long long ans, maxp, minp;
        ans = maxp = minp = arr[0];
        for (int i = 1; i < n; i++) {
            if (arr[i] < 0) swap(maxp, minp);

            maxp = max<long long int>(maxp * arr[i], arr[i]);
            minp = min<long long int>(minp * arr[i], arr[i]);
            ans = max<long long>(ans, maxp);
        }
        return ans;
    }
};


// Method 3
// Minimum Product Subarray
class Solution {
public:
    long long maxProduct(vector<int> arr, int n) {
        long long ans, maxp, minp;
        ans = maxp = minp = arr[0];
        for (int i = 1; i < n; i++) {
            if (arr[i] < 0) swap(maxp, minp);

            maxp = max<long long int>(maxp * arr[i], arr[i]);
            minp = min<long long int>(minp * arr[i], arr[i]);
            ans = min<long long>(ans, minp);
        }
        return ans;
    }
};
