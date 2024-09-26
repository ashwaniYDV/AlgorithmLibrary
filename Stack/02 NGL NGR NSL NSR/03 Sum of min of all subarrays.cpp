// https://leetcode.com/problems/sum-of-subarray-minimums/
// https://www.geeksforgeeks.org/sum-of-minimum-elements-of-all-subarrays/

/*
Given an array of integers arr, find the sum of min(b), where b ranges over every (contiguous) subarray of nums. 
Since the answer may be large, return the answer modulo 10^9 + 7.

Example 1:
Input: arr = [3,1,2,4]
Output: 17
Explanation: 
Subarrays are [3], [1], [2], [4], [3,1], [1,2], [2,4], [3,1,2], [1,2,4], [3,1,2,4]. 
Minimums are 3, 1, 2, 4, 1, 1, 2, 1, 1, 1.
Sum is 17.

Example 2:
Input: arr = [11,81,94,43,3]
Output: 444
 

Constraints:
1 <= arr.length <= 3 * 10^4
1 <= arr[i] <= 3 * 10^4
*/


/*
Efficient Approach: 
The general intuition for solution to the problem is to find sum(A[i] * f(i)), where f(i) is the number of subarrays in which A[i] is the minimum.

In order to find f[i], we need to find out: 
left[i], the length of strictly larger numbers on the left of A[i], 
right[i], the length of larger numbers on the right of A[i].
We make two arrays left[ ] and right[ ] such that: 
left[i] + 1 equals to the number of subarrays ending with A[i], and A[i] is only single minimum. 
Similarly, right[i] + 1 equals to the number of subarrays starting with A[i], and A[i] is first minimum.
Finally, f(i) = (left[i]) * (right[i]), where f[i] equals total number of subarrays in which A[i] is minimum.
Below is the implementation of above approach.

The last thing that needs to be mentioned for handling duplicate elements:
Method: Set strict less/greater and non-strict less/greater. The order doesn't matter.
*/



/*
Note equality and inequality can be included in either left or right side but not on both sides.

To understand why we cannot take equality on both sides:
nums = {1, 1, 1}

If we take equality on both sides:
res = 1*3 + 2*2 + 3*1 = 10
which is wrong

Correct (equality on right side)
res = 1*3 + 1*2 + 1*1 = 6

Correct (equality on left side)
res = 1*1 + 1*2 + 1*3 = 6
*/

class Solution {
public:
    int sumSubarrayMins(vector<int>& nums) {
        int n = nums.size();
        stack<int> st;
        // nsl = (NSL+1)th idx, nsr = (NSR - 1)th idx
        vector<int> nsl(n), nsr(n);
        
        // getting number of element strictly larger than nums[i] on Left.
        for(int i = 0; i < n; i++) {
            // here equality is not included
            while(!st.empty() && nums[st.top()] > nums[i]) {
                st.pop();
            }
            if(!st.empty()) {
                nsl[i] = st.top() + 1;
            } else {
                nsl[i] = 0;
            }
            st.push(i);
        }
        
        while(!st.empty()) st.pop();
        
        // getting number of element larger or equal to nums[i] on Right.
        for(int i = n-1; i >= 0; i--) {
            // here equality is included
            while(!st.empty() && nums[st.top()] >= nums[i]) {
                st.pop();
            }
            if(!st.empty()) {
                nsr[i] = st.top() - 1;
            } else {
                nsr[i] = n-1;
            }
            st.push(i);
        }
        
        int res = 0;
        for(int i = 0; i < n; i++) {
            int left = i - nsl[i] + 1;
            int right = nsr[i] - i + 1;
            int cnt = left * right;
            res += nums[i] * cnt;
        }
        
        return res;
    }
};















class Solution {
public:
    const int mod = 1e9+7;
    
    int sumSubarrayMins(vector<int>& nums) {
        int n = nums.size();
        stack<int> st;
        // nsl = (NSL+1)th idx, nsr = (NSR - 1)th idx
        vector<int> nsl(n), nsr(n);
        
        // getting number of elements strictly larger than nums[i] on Left.
        for(int i = 0; i < n; i++) {
            // here equality is not included
            while(!st.empty() && nums[st.top()] > nums[i]) {
                st.pop();
            }
            if(!st.empty()) {
                nsl[i] = st.top() + 1;
            } else {
                nsl[i] = 0;
            }
            st.push(i);
        }
        
        while(!st.empty()) st.pop();
        
        // getting number of elements larger than or equal to nums[i] on Right.
        for(int i = n-1; i >= 0; i--) {
            // here equality is included
            while(!st.empty() && nums[st.top()] >= nums[i]) {
                st.pop();
            }
            if(!st.empty()) {
                nsr[i] = st.top() - 1;
            } else {
                nsr[i] = n-1;
            }
            st.push(i);
        }
        
        long long res = 0;
        for(int i = 0; i < n; i++) {
            int left = i - nsl[i] + 1;
            int right = nsr[i] - i + 1;
            long long cnt = (left % mod * right % mod) % mod;
            res = (res + (nums[i] % mod * cnt % mod)) % mod;
            
            if(res < 0) res += mod;
        }
        
        return (int)res;
    }
};






class Solution {
public:
    const int mod = 1e9+7;
    
    int sumSubarrayMins(vector<int>& nums) {
        int n = nums.size();
        stack<int> st;
        // nsl = (NSL+1)th idx, nsr = (NSR - 1)th idx
        vector<int> nsl(n), nsr(n);
        
        // getting number of elements larger than or equal to nums[i] on Left.
        for(int i = 0; i < n; i++) {
            // here equality is included
            while(!st.empty() && nums[st.top()] >= nums[i]) {
                st.pop();
            }
            if(!st.empty()) {
                nsl[i] = st.top() + 1;
            } else {
                nsl[i] = 0;
            }
            st.push(i);
        }
        
        while(!st.empty()) st.pop();
        
        // getting number of elements strictly larger than nums[i] on Right.
        for(int i = n-1; i >= 0; i--) {
            // here equality is not included
            while(!st.empty() && nums[st.top()] > nums[i]) {
                st.pop();
            }
            if(!st.empty()) {
                nsr[i] = st.top() - 1;
            } else {
                nsr[i] = n-1;
            }
            st.push(i);
        }
        
        long long res = 0;
        for(int i = 0; i < n; i++) {
            int left = i - nsl[i] + 1;
            int right = nsr[i] - i + 1;
            long long cnt = (left % mod * right % mod) % mod;
            res = (res + (nums[i] % mod * cnt % mod)) % mod;
            
            if(res < 0) res += mod;
        }
        
        return (int)res;
    }
};
