// https://leetcode.com/problems/constrained-subsequence-sum/

/*
Given an integer array nums and an integer k, return the maximum sum of a non-empty subsequence of that array 
such that for every two consecutive integers in the subsequence, nums[i] and nums[j], where i < j, the condition j - i <= k is satisfied.

Example 1:
Input: nums = [10,2,-10,5,20], k = 2
Output: 37
Explanation: The subsequence is [10, 2, 5, 20].

Example 2:
Input: nums = [-1,-2,-3], k = 1
Output: -1
Explanation: The subsequence must be non-empty, so we choose the largest number.

Constraints:
1 <= k <= nums.length <= 10^5
-10^4 <= nums[i] <= 10^4
*/


/*
Let dp[i] be the solution for the prefix of the array that ends at index i, if the element at index i is in the subsequence.
dp[i] = nums[i] + max(0, dp[i-k], dp[i-k+1], ..., dp[i-1])

Use a heap with the sliding window technique to optimize the dp.

Use a mono with the sliding window technique to optimize the dp.

NOTE:
This technique is known as monotonic queue or monoque where elements in deque are maintained either in increasin or decreasingorder 
so as to resemble priority queue but with linear time.

Concept of max of all subarrays of size k question (sliding window) is used here.
*/



// Time = O(n ^ 2), Space = O(n)
class Solution {
public:
    int constrainedSubsetSum(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> dp(n);

        for (int i = 0; i < n; i++) {
            dp[i] = nums[i];
        }

        int res = nums[0];
        for (int i = 1; i < n; i++) {
            for (int j = max(0, i - k); j < i; j++) {
                dp[i] = max(dp[i], nums[i] + dp[j]);
            }
            res = max(res, dp[i]);
        }

        return res;
    }
};










// Time = O(n * logn), Space = O(n + k)
// Variation 1
class Solution {
public:
    int constrainedSubsetSum(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> dp(n);

        for (int i = 0; i < n; i++) {
            dp[i] = nums[i];
        }

        int res = nums[0];
        multiset<int, greater<>> st;
        st.insert(dp[0]);
        for (int i = 1; i < n; i++) {
            if (st.size() > k) {
                st.erase(st.find(dp[i - k - 1]));
            }
            dp[i] = max(dp[i], nums[i] + *st.begin());
            res = max(res, dp[i]);

            st.insert(dp[i]);
        }

        return res;
    }
};



// Variation 2
class Solution {
public:
    int constrainedSubsetSum(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> dp(n);

        for (int i = 0; i < n; i++) {
            dp[i] = nums[i];
        }

        int res = nums[0];
        multiset<int, greater<>> st;
        st.insert(dp[0]);
        for (int i = 1; i < n; i++) {
            dp[i] = max(dp[i], nums[i] + *st.begin());
            res = max(res, dp[i]);

            st.insert(dp[i]);
            if (st.size() > k) {
                st.erase(st.find(dp[i - k]));
            }
        }

        return res;
    }
};









// Time = O(n), Space = O(n + k)

// Variation 1
class Solution {
public:
    int constrainedSubsetSum(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> dp(n);

        for (int i = 0; i < n; i++) {
            dp[i] = nums[i];
        }

        int res = nums[0];
        deque<int> dq;
        dq.push_back(0);
        for (int i = 1; i < n; i++) {
            while ((!dq.empty()) && dq.front() < i - k) {
                dq.pop_front();
            }
            dp[i] = max(dp[i], nums[i] + (dq.empty() ? 0 : dp[dq.front()]));
            res = max(res, dp[i]);

            while ((!dq.empty()) && dp[i] >= dp[dq.back()]) {
                dq.pop_back();
            }
            dq.push_back(i);
        }

        return res;
    }
};




// Variation 2
class Solution {
public:
    int constrainedSubsetSum(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> dp(n);

        for (int i = 0; i < n; i++) {
            dp[i] = nums[i];
        }

        int res = nums[0];
        deque<int> dq;
        dq.push_back(0);
        for (int i = 1; i < n; i++) {
            dp[i] = max(dp[i], nums[i] + (dq.empty() ? 0 : dp[dq.front()]));
            res = max(res, dp[i]);

            while ((!dq.empty()) && dq.front() <= i - k) {
                dq.pop_front();
            }
            while ((!dq.empty()) && dp[i] >= dp[dq.back()]) {
                dq.pop_back();
            }
            dq.push_back(i);
        }

        return res;
    }
};
