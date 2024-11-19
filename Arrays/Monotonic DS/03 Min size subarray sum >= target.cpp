// Min Size Subarray Sum >= target (array has both +ve -ve integers) [monotonic queue]
// https://leetcode.com/problems/shortest-subarray-with-sum-at-least-k/

/*
Given an integer array nums and an integer k, return the length of the shortest non-empty subarray of nums with a sum of at least k. 
If there is no such subarray, return -1.

Input: nums = [2,-1,2], k = 3
Output: 3

Input: nums = [1,2], k = 4
Output: -1
 

Constraints:
1 <= nums.length <= 10^5
-10^5 <= nums[i] <= 10^5
1 <= k <= 10^9
*/


/*
// https://leetcode.com/problems/shortest-subarray-with-sum-at-least-k/discuss/143726/C%2B%2BJavaPython-O(N)-Using-Deque
// Monotonic queue or monoque concept

What makes this problem hard is that we have negative values (otherwise we could have used sliding window or binary search).

Complexity:
Time O(N)
Space O(N)


How to think of such solutions?
Basic idea, for array starting at every A[i], find the shortest one with sum at leat K.
In my solution, for pref[i], find the smallest j that pref[j] - pref[i] >= K.
Keep this in mind for understanding two while loops.

What is the purpose of first while loop?
For the current prefix sum pref[i], it covers all subarray ending at A[i-1].
We want know if there is a subarray, which starts from an index, ends at A[i-1] and has at least sum K.
So we start to compare pref[i] with the smallest prefix sum in our deque, which is pref[d[0]], hoping that pref[i] - pref[d[0]] >= K.
So if pref[i] - pref[d[0]] >= K, we can update our result res = min(res, i - d.popleft()).
The while loop helps compare one by one, until this condition isn't valid anymore.

What is the purpose of second while loop?
To keep pref[d[i]] increasing in the deque.

Why keep the deque increase?
If pref[i] <= pref[d.back()] and moreover we already know that i > d.back(), it means that compared with d.back(),
pref[i] can help us make the subarray length shorter and sum bigger. 
So no need to keep d.back() in our deque.

(By sum bigger here means {pref[future_i] - pref[i]} > {pref[future_i] - pref[d.back()]} since pref[i] <= pref[d.back()])
*/



// Method 1.1
class Solution {
public:
    int shortestSubarray(vector<int>& a, int k) {
        int n = a.size();

        vector<long long> pref(n);
        pref[0] = a[0];
        for (int i = 1; i < n; i++) {
            pref[i] = a[i] + pref[i - 1];
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


// Method 1.2
class Solution {
public:
    int shortestSubarray(vector<int>& a, int k) {
        int n = a.size();
        deque<int> d;
        int res = n + 1;

        for (int i = 0; i < n; i++) {
            if (i > 0) a[i] += a[i - 1];

            if (a[i] >= k) res = min(res, i + 1);

            while (!d.empty() && a[i] - a[d.front()] >= k) {
                res = min(res, i - d.front());
                d.pop_front();
            }
            while (!d.empty() && a[i] <= a[d.back()]) {
                d.pop_back();
            }

            d.push_back(i);
        }
        return res <= n ? res : -1;
    }
};







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


// Method 2: Binary Search (FFFFFFFTTTTT)
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