// https://leetcode.com/problems/sliding-window-maximum/description/

/*
You are given an array of integers nums, 
there is a sliding window of size k which is moving from the very left of the array to the very right. 
You can only see the k numbers in the window. 
Each time the sliding window moves right by one position.
Return the max sliding window.

Input: nums = [1,3,-1,-3,5,3,6,7], k = 3
Output: [3,3,5,5,6,7]
*/

// Method 1
class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> res;
        deque<int> dq;

        for (int i = 0; i < k; ++i) {
            // For every element, previous smaller elements are useless so remove them from deque
            while ((!dq.empty()) && nums[i] >= nums[dq.back()]) {
                dq.pop_back();
            }

            dq.push_back(i);
        }

        res.push_back(nums[dq.front()]);

        for (int i = k; i < n; ++i) {
            // Remove the elements which are out of this window
            while ((!dq.empty()) && dq.front() <= i - k) {
                dq.pop_front();
            }

            // Remove all elements smaller than the currently being added element 
            // (remove useless elements) this makes deque monotonic
            while ((!dq.empty()) && nums[i] >= nums[dq.back()]) {
                dq.pop_back();
            }

            dq.push_back(i);

            res.push_back(nums[dq.front()]);
        }

        return res;
    }
};


// Method 2
class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> res;
        multiset<int, greater<int>> st;
        
        for(int i = 0; i < k; i++) {
            st.insert(nums[i]);
        }
        res.push_back(*st.begin());
        
        for(int i = k; i < n; i++) {
            st.erase(st.find(nums[i - k]));
            st.insert(nums[i]);
            res.push_back(*st.begin());
        }
        return res;
    }
};