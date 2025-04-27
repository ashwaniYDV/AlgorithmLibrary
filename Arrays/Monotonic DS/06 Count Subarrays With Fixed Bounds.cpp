// https://leetcode.com/problems/count-subarrays-with-fixed-bounds/
// https://leetcode.com/problems/count-subarrays-with-fixed-bounds/solutions/6687441/sliding-window-monotonic-queue-with-images-example-walkthrough/?envType=daily-question&envId=2025-04-26

/*
You are given an integer array nums and two integers minK and maxK.
A fixed-bound subarray of nums is a subarray that satisfies the following conditions:
* The minimum value in the subarray is equal to minK.
* The maximum value in the subarray is equal to maxK.
Return the number of fixed-bound subarrays.

Input: nums = [1,3,5,2,7,5], minK = 1, maxK = 5
Output: 2
Explanation: The fixed-bound subarrays are [1,3,5] and [1,3,5,2].

Input: nums = [1,1,1,1], minK = 1, maxK = 1
Output: 10
Explanation: Every subarray of nums is a fixed-bound subarray. There are 10 possible subarrays.
 
Constraints:
2 <= nums.length <= 10^5
1 <= nums[i], minK, maxK <= 10^6
*/


// TLE
class Solution {
public:
    long long countSubarrays(vector<int>& nums, int minK, int maxK) {
        long count = 0;
        for (int i = 0; i < nums.size(); i++) {
            int mini = INT_MAX, maxi = INT_MIN;
            for (int j = i; j < nums.size(); j++) {
                mini = min(mini, nums[j]);
                maxi = max(maxi, nums[j]);
                if (mini == minK && maxi == maxK) ++count;
            }
        }
        return count;
    }
};



class Solution {
public:
    long long countSubarrays(vector<int>& nums, int minK, int maxK) {
        long long cnt = 0, left = 0;
        deque<int> dq_min, dq_max;

        for (int i = 0; i < nums.size(); ++i) {
            if (nums[i] < minK || nums[i] > maxK) {
                dq_min.clear();
                dq_max.clear();
                left = i + 1;
                continue;
            }

            while (!dq_min.empty() && nums[dq_min.back()] >= nums[i]) {
                 dq_min.pop_back();
            }
            dq_min.push_back(i);

            while (!dq_max.empty() && nums[dq_max.back()] <= nums[i]) {
                dq_max.pop_back();
            }
            dq_max.push_back(i);

            if (nums[dq_min.front()] == minK && nums[dq_max.front()] == maxK) {
                int start = min(dq_min.front(), dq_max.front());
                cnt += (start - left + 1);
                cout << cnt << " ";
            }
        }
        return cnt;
    }
};
