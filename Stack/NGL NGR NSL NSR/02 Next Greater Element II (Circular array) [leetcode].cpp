// https://leetcode.com/problems/next-greater-element-ii/

/*
Given a circular integer array nums (i.e., the next element of nums[nums.length - 1] is nums[0]), return the next greater number for every element in nums.
The next greater number of a number x is the first greater number to its traversing-order next in the array, 
which means you could search circularly to find its next greater number. If it doesn't exist, return -1 for this number.


Input: nums = [1,2,1]
Output: [2,-1,2]
Explanation: 
    The first 1's next greater number is 2; 
    The number 2 can't find next greater number. 
    The second 1's next greater number needs to search circularly, which is also 2.

Input: nums = [1,2,3,4,3]
Output: [2,3,4,-1,4]
*/



// Method 1: (Space = n)
/*
Loop once, we can get the Next Greater Number of a normal array.
Loop twice, we can get the Next Greater Number of a circular array
*/
class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n = nums.size();
        vector<int> res(n);
        stack<int> st;

        for(int i = 2 * n - 1; i >= 0; i--) {
            while(!st.empty() && nums[st.top() % n] <= nums[i % n]) {
                st.pop();
            }
            
            if(!st.empty()) {
                res[i % n] = nums[st.top() % n];
            } else {
                res[i % n] = -1;
            }
            st.push(i);
        }
        
        return res;
    }
};


// Method 2: (Space = 2n)
class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n = nums.size();
        vector<int> a(nums.begin(), nums.end());
        
        for(int i = 0; i < n; i++) {
            a.push_back(nums[i]);
        }
        
        int m = 2 * n;
        vector<int> res(m);
        stack<int> st;
        for(int i = m-1; i >= 0; i--) {
            while(!st.empty() && a[st.top()] <= a[i]) {
                st.pop();
            }
            
            if(!st.empty()) {
                res[i] = a[st.top()];
            } else {
                res[i] = -1;
            }
            st.push(i);
        }
        
        vector<int> temp;
        for(int i = 0; i < n; i++) {
            temp.push_back(res[i]);
        }
        
        return temp;
    }
};
