// https://leetcode.com/problems/maximum-absolute-sum-of-any-subarray/

/*
The absolute sum of a subarray [numsl, numsl+1, ..., numsr-1, numsr] is abs(numsl + numsl+1 + ... + numsr-1 + numsr).
Return the maximum absolute sum of any (possibly empty) subarray of nums.

Input: nums = [1,-3,2,3,-4]
Output: 5
Explanation: The subarray [2,3] has absolute sum = abs(2+3) = abs(5) = 5.

Input: nums = [2,-5,1,-4,3,-2]
Output: 8
Explanation: The subarray [-5,1,-4] has absolute sum = abs(-5+1-4) = abs(-8) = 8.
 
Constraints:
1 <= nums.length <= 10^5
-10^4 <= nums[i] <= 10^4
*/


// Method 1
class Solution {
public:
    int maxAbsoluteSum(vector<int>& a) {
        int n = a.size();
        int res = INT_MIN, maxEngindHere = 0, minEndingHere = 0;

        for(int i = 0; i < n; i++) {
            maxEngindHere += a[i];
            minEndingHere += a[i];

            res = max({res, maxEngindHere, abs(minEndingHere)});

            if(maxEngindHere < 0) maxEngindHere = 0;
            if(minEndingHere > 0) minEndingHere = 0;
        }

        return res;
    }
};



// Method 2
class Solution {
public:
    int kadanes(vector<int>& a) {
        int n = a.size();
        int res = INT_MIN, maxEngindHere = 0;
        for(int i = 0; i < n; i++) {
            maxEngindHere += a[i];
            res = max(res, maxEngindHere);
            if(maxEngindHere < 0) maxEngindHere = 0;
        }
        return res;
    }

    int maxAbsoluteSum(vector<int>& a) {
        int res = kadanes(a);
        
        // negate the numbers
        for(int& x: a) x = -x;
        
        return max(res, kadanes(a));
    }
};