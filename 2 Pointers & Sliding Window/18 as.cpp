// https://leetcode.com/problems/longest-nice-subarray/description/

/*
You are given an array nums consisting of positive integers.
We call a subarray of nums nice if the bitwise AND of every pair of elements that are in different positions in the subarray is equal to 0.
Return the length of the longest nice subarray.

Input: nums = [1,3,8,48,10]
Output: 3
Explanation: The longest nice subarray is [3,8,48]. This subarray satisfies the conditions:
- 3 AND 8 = 0.
- 3 AND 48 = 0.
- 8 AND 48 = 0.
It can be proven that no longer nice subarray can be obtained, so we return 3.

Input: nums = [3,1,5,11,13]
Output: 1
Explanation: The length of the longest nice subarray is 1. Any subarray of length 1 can be chosen.
 

Constraints:
1 <= nums.length <= 10^5
1 <= nums[i] <= 10^9
*/


class Solution {
public:
    bool check(vector<int>& bits) {
        for(int x: bits) {
            if(x > 1) return 0;
        }
        return 1;
    }

    void update(int i, int delta, int n, vector<int>& a, vector<int>& bits) {
        for(int j = 0; j < 32; j++) {
            if(a[i] & (1 << j)) {
                bits[j] += delta;
            }
        }
    }
    
    int longestNiceSubarray(vector<int>& a) {
        int n = a.size();
        vector<int> bits(32, 0);

        int l = 0, res = 0;
        for(int r = 0; r < n; r++) {
            update(r, 1, n, a, bits);

            while(!check(bits)) {
                update(l, -1, n, a, bits);
                l++;
            }

            res = max(res, r - l + 1);
        }

        return res;
    }
};