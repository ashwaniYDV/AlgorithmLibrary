// Min Size Subarray Sum >= target (array has only +ve integers)
// https://leetcode.com/problems/minimum-size-subarray-sum/

/*
Given an array of positive integers nums and a positive integer target, 
return the minimal length of a contiguous subarray [numsl, numsl+1, ..., numsr-1, numsr] of which the sum is greater than or equal to target. 
If there is no such subarray, return 0 instead.


Input: target = 7, nums = [2,3,1,2,4,3]
Output: 2

Input: target = 4, nums = [1,4,4]
Output: 1

Input: target = 11, nums = [1,1,1,1,1,1,1,1]
Output: 0
 

Constraints:
1 <= target <= 10^9
1 <= nums.length <= 10^5
1 <= nums[i] <= 10^5
*/





// Method 1
class Solution {
public:
    const int INF = 1e9;

    int minSubArrayLen(int target, vector<int>& nums) {
        int n = nums.size();
        
        int left = 0, res = INF, sum = 0;
        
        for(int right = 0; right < n; right++) {
            sum += nums[right];
            
            while(sum - nums[left] >= target) {
                sum -= nums[left];
                left++;
            }
            
            if(sum >= target) res = min(res, right - left + 1);
        }
       
        sum = 0;
        for(int i = 0; i < n; i++) sum += nums[i];
        
        if(res == INF) return 0;
        
        if(sum < target) return 0;
        return res;
    }
};




// Method 2.1
class Solution {
public:
    int shortestSubarray(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> pref(n);
        pref[0] = nums[0];
        for (int i = 1; i < n; i++) {
            pref[i] = nums[i] + pref[i - 1];
        }

        deque<int> d;
        int res = n + 1;

        for (int i = 0; i < n; i++) {
            if (pref[i] >= k) res = min(res, i + 1);

            while (!d.empty() && pref[i] - pref[d.front()] >= k) {
                res = min(res, i - d.front());
                d.pop_front();
            }
            while (!d.empty() && pref[d.back()] >= pref[i]) {
                d.pop_back();
            }

            d.push_back(i);
        }
        return res <= n ? res : -1;
    }
};


// Method 2.2
class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int n = nums.size();
        deque<int> d;
        int res = n + 1;

        for (int i = 0; i < n; i++) {
            if (i > 0) nums[i] += nums[i - 1];

            if (nums[i] >= target) res = min(res, i + 1);

            while (!d.empty() && nums[i] - nums[d.front()] >= target) {
                res = min(res, i - d.front());
                d.pop_front();
            }
            while (!d.empty() && nums[d.back()] >= nums[i]) {
                d.pop_back();
            }

            d.push_back(i);
        }
        return res <= n ? res : 0;
    }
};





// Method 3: Binary Search (FFFFFFFTTTTT)
class Solution {
public:
    int n;
    bool check(int mid, int target, vector<int>& nums) {
        int sum = 0;
        for(int i = 0; i < mid; i++) {
            sum += nums[i];
        }
        if(sum >= target) return true;
        
        for(int i = mid; i < n; i++) {
            sum -= nums[i - mid];
            sum += nums[i];
            if(sum >= target) return true;
        }
        return false;
    }
    
    int minSubArrayLen(int target, vector<int>& nums) {
        n = nums.size();
        
        int lo = 1, hi = n;
        
        while(lo < hi) {
            int mid = lo + (hi - lo) / 2;
            
            if(check(mid, target, nums)) {
                hi = mid;
            } else {
                lo = mid + 1;
            }
        }
        
        int sum = 0;
        for(int i = 0; i < n; i++) sum += nums[i];
        
        if(lo == n && sum < target) return 0;
        return lo;
    }
};