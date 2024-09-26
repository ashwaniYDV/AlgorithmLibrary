// https://leetcode.com/problems/longest-continuous-subarray-with-absolute-diff-less-than-or-equal-to-limit/

/*
Given an array of integers nums and an integer limit, 
return the size of the longest non-empty subarray such that the absolute difference between any two elements of this subarray is less than or equal to limit.

Input: nums = [8,2,4,7], limit = 4
Output: 2
*/

// Method 1
class Solution {
public:
    int longestSubarray(vector<int>& nums, int limit) {
        int n = nums.size();
        multiset<int> st;
        
        int l = 0, res = 0;
        for(int r = 0; r < n; r++) {
            st.insert(nums[r]);

            while(*st.rbegin() - *st.begin() > limit) {
                st.erase(st.find(nums[l]));
                l++;
            }

            res = max(res, r - l + 1);
        }

        return res;
    }
};


// Method 2: Two Heaps
class Solution {
public:
    int longestSubarray(vector<int>& nums, int k) {
        priority_queue<pair<int, int>> maxHeap;
        priority_queue<pair<int, int>, vector<pair<int, int>>,greater<pair<int, int>>> minHeap;

        int l = 0, res = 0;

        for (int r = 0; r < nums.size(); ++r) {
            maxHeap.push({nums[r], r});
            minHeap.push({nums[r], r});

            // Check if the absolute difference between the maximum and minimum values in the current window exceeds the limit
            while (maxHeap.top().first - minHeap.top().first > k) {
                // Move the left pointer to the right until the condition is satisfied.
                l = min(maxHeap.top().second, minHeap.top().second);

                // Remove elements from the heaps that are outside the current window
                while (maxHeap.top().second <= l) {
                    maxHeap.pop();
                }
                while (minHeap.top().second <= l) {
                    minHeap.pop();
                }
                l++;
            }

            // Update maxLength with the length of the current valid window
            res = max(res, r - l + 1);
        }

        return res;
    }
};



// Method 3: Two Deques
// https://leetcode.com/problems/longest-continuous-subarray-with-absolute-diff-less-than-or-equal-to-limit/editorial/
/*
Intuition
---------
* While heaps are commonly used to track max and min values, their frequent insertion and removal operations are inefficient (O(logn) time). 
  Deques offer efficient O(1) time complexity for adding and removing elements from both ends and are more suitable for this problem.
* We use two deques for this problem. 
* One deque maintains numbers in decreasing order, ensuring the largest number in the window is always at the front. 
  If a new number exceeds those at the deque's end, we remove those elements since they can no longer be the maximum in the current window.
* Similarly, the other deque will maintain the numbers in increasing order, ensuring the smallest number in the window is always at the front. 
  If a new number is smaller than those at the deque's end, it replaces them, ensuring accuracy for the current window's minimum.
* These deques hold all the potential minimum and maximum values for the current and future windows.
* If abs diff bw max and min values at front of the deques exceeds the limit, we shrink the window by moving the left pointer. 
*/
class Solution {
public:
    int longestSubarray(vector<int>& nums, int k) {
        int n = nums.size();
        deque<int> inc; // (minDeque) contain smallest ele in front
        deque<int> dec; // (maxDeque) contain largest ele in front
        int l = 0, res = 0;

        for (int r = 0; r < n; r++) {
            int el = nums[r];
            // Maintain the minDeque in increasing order
            while (!inc.empty() && el < inc.back()) {
                inc.pop_back();
            }
            inc.push_back(el);

            // Maintain the maxDeque in decreasing order
            while (!dec.empty() && el > dec.back()) {
                dec.pop_back();
            }
            dec.push_back(el);

            // Check if the current window exceeds the limit
            while(dec.front() - inc.front() > k) {
                // Remove the elements that are out of the current window
                if (nums[l] == dec.front()) {
                    dec.pop_front();
                }
                if (nums[l] == inc.front()) {
                    inc.pop_front();
                }
                l++;
            }

            res = max(res, r - l + 1);
        }
        return res;
    }
};