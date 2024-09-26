// https://leetcode.com/problems/maximum-width-ramp/description/

/*
A ramp is a pair (i, j) for which i < j and nums[i] <= nums[j]. 
The width of such a ramp is j - i.
Return the max width of a ramp in nums. 
If there is no ramp in nums, return 0. 

Input: nums = [6,0,8,2,1,5]
Output: 4
Explanation: The maximum width ramp is achieved at (i, j) = (1, 5): nums[1] = 0 and nums[5] = 5.

Input: nums = [9,8,1,0,1,9,4,0,4,1]
Output: 7
Explanation: The maximum width ramp is achieved at (i, j) = (2, 9): nums[2] = 1 and nums[9] = 1.
*/


// Method 1: O(nlogn)
/*
Intuition:
---------
Keep a monotonic decreasing stack.
For each number, 
    if the number is smaller the the last ele in stack => push it into the stack
    else binary search the first smaller number in the stack.
*/
class Solution {
public:
    int maxWidthRamp(vector<int>& nums) {
        int n = nums.size();
        
        vector<int> monotonSt;
        int res = 0;

        for(int i = 0; i < n; i++) {
            if(monotonSt.empty() || nums[i] < nums[monotonSt.back()]) {
                monotonSt.push_back(i);
            } else {
                int l = 0, r = monotonSt.size() - 1, mid = 0;
                // FFFTTT
                while (l <= r) {
                    mid = (l + r) / 2;
                    if (nums[monotonSt[mid]] <= nums[i]) {
                        r = mid - 1;
                    } else {
                        l = mid + 1;
                    }
                }
                res = max(res, i - monotonSt[l]);
            }
        }

        return res;
    }
};


// Method 2: O(n)
class Solution {
public:
    int maxWidthRamp(vector<int>& nums) {
        int n = nums.size();
        
        stack<int> monotonSt;
        monotonSt.push(0);

        for(int i = 1; i < n; i++) {
            if(nums[i] < nums[monotonSt.top()]) {
                monotonSt.push(i);
            }
        }

        int res = 0;
        for(int r = n-1; r >= 0; r--) {
            while(!monotonSt.empty() && nums[monotonSt.top()] <= nums[r]) {
                int l = monotonSt.top();
                res = max(res, r - l);
                monotonSt.pop();
            }
        }
        return res;
    }
};