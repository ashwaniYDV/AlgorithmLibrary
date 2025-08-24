// https://leetcode.com/problems/longest-subarray-of-1s-after-deleting-one-element/description/

/*
Given a binary array nums, you should delete one element from it.
Return the size of the longest non-empty subarray containing only 1's in the resulting array. Return 0 if there is no such subarray.

 
Input: nums = [1,1,0,1]
Output: 3
Explanation: After deleting the number in position 2, [1,1,1] contains 3 numbers with value of 1's.

Input: nums = [0,1,1,1,0,1,1,0,1]
Output: 5
Explanation: After deleting the number in position 4, [0,1,1,1,1,1,0,1] longest subarray with value of 1's is [1,1,1,1,1].

Input: nums = [1,1,1]
Output: 2
Explanation: You must delete one element.
*/


// Method 1
class Solution {
public:
    int longestSubarray(vector<int>& a) {
        int n = a.size();
        vector<int> left(n), right(n);

        left[0] = a[0];
        right[n - 1] = a[n - 1];
            
        for (int i = 1; i < n; i++) {
            if (a[i] == 1)
                left[i] = left[i - 1] + 1;
            else
                left[i] = 0;
        }

        for (int i = n - 2; i >= 0; i--) {
            if (a[i] == 1)
                right[i] = right[i + 1] + 1;
            else
                right[i] = 0;
        }

        int res = 0;
        for (int i = 0; i < n; i++) {
            int l = i-1 >= 0 ? left[i - 1] : 0;
            int r = i+1 < n ? right[i + 1] : 0;
            res = max(res, l + r);
        }

        return res;a
    }
};


// Method 2
class Solution {
public:
    int longestSubarray(vector<int>& a) {
        int n = a.size();
        int cur = 0, prev = 0, res = 0;
        for(int i = 0; i < a.size(); i++) {
            if(a[i]) 
                cur++;
            else {
                prev = cur;
                cur = 0;
            }
            res = max(res, cur + prev);
        }
        return res == n ? n-1 : res;
    }
};


// Method 3: (sliding window)
class Solution {
public:
    int longestSubarray(vector<int>& a) {
        int n = a.size();
        int zeroCnt = 0, res = 0;

        int l = 0;
        for (int r = 0; r < n; r++) {
            zeroCnt += (a[r] == 0);
                          
            while (zeroCnt > 1) {
                zeroCnt -= (a[l] == 0);
                l++;
            }
              
            res = max(res, r - l);
        }

        return res;
    }
};