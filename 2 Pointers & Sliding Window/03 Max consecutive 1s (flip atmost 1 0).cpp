// https://leetcode.com/problems/max-consecutive-ones-ii/

/*
Given a binary array nums, 
return max number of consecutive 1's in the array if you can flip at most one 0.

Input: nums = [1,0,1,1,0]
Output: 4
Explanation: 
- If we flip the first zero, nums becomes [1,1,1,1,0] and we have 4 consecutive ones.
- If we flip the second zero, nums becomes [1,0,1,1,1] and we have 3 consecutive ones.
The max number of consecutive ones is 4.
*/

// Method 1
class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& A) {
        int n = A.size();
        vector<int> l(n, 0), r(n, 0);

        int res = 0;
        
        int sum = 0;
        for(int i = 0; i < n; i++) {
            sum += A[i];
            if(A[i] == 0) sum = 0;
            l[i] = sum;

            res = max(res, sum);
        }

        sum = 0;
        for(int i = n-1; i >= 0; i--) {
            sum += A[i];
            if(A[i] == 0) sum = 0;
            r[i] = sum;
            res = max(res, sum);
        }

        for(int i = 0; i < n; i++) {
            if(A[i] == 0) {
                res = max(res, 1 + (i-1 >= 0 ? l[i-1] : 0) + (i+1 < n ? r[i+1] : 0));
            }
        }

        return res;
    }
};



// Method 2
class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& a) {
        int k = 1;
        int n = a.size();
        int zeroCount = 0, res = 0;
        int l = 0;

        for (int r = 0; r < n; r++) {
            if (a[r] == 0) {
                zeroCount++;
            }

            while (zeroCount > k) {
                if (a[l] == 0) {
                    zeroCount--;
                }
                l++;
            }

            res = max(res, r - l + 1);
        }
        
        return res;
    }
};