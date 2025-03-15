// https://leetcode.com/problems/house-robber-iv/

/*
There are several consecutive houses along a street, each of which has some money inside. 
There is also a robber, who wants to steal money from the homes, but he refuses to steal from adjacent homes.
The capability of the robber is the maximum amount of money he steals from one house of all the houses he robbed.
You are given an integer array nums representing how much money is stashed in each house. 
You are also given an integer k, representing the minimum number of houses the robber will steal from. 
It is always possible to steal at least k houses.
Return the minimum capability of the robber out of all the possible ways to steal at least k houses.


Input: nums = [2,3,5,9], k = 2
Output: 5
Explanation: 
There are three ways to rob at least 2 houses:
- Rob the houses at indices 0 and 2. Capability is max(nums[0], nums[2]) = 5.
- Rob the houses at indices 0 and 3. Capability is max(nums[0], nums[3]) = 9.
- Rob the houses at indices 1 and 3. Capability is max(nums[1], nums[3]) = 9.
Therefore, we return min(5, 9, 9) = 5.


Constraints:
1 <= nums.length <= 10^5
1 <= nums[i] <= 10^9
1 <= k <= (nums.length + 1)/2
*/

/*
Intuition
---------
Problems that require (minimizing the maximum) or (maximizing the minimum) often suggest a binary search approach. 
Instead of searching through indices or subsets directly, we can binary search on the capability (i.e., something like the max amount stolen from any single house). 
By determining whether a given capability is achievable, we can efficiently narrow down the possible solutions.
*/

class Solution {
public:
    bool check(int mid, int n, vector<int>& a, int k) {
        int cnt = 0;
        for(int i = 0; i < n; i++) {
            if(a[i] <= mid) {
                cnt++;
                i++; // Skip the next house to maintain the non-adjacent condition
            }
        }

        return cnt >= k;
    }

    // FFFFFFTTTTTT
    int minCapability(vector<int>& a, int k) {
        int n = a.size();
        int lo = *min_element(a.begin(), a.end()), hi = *max_element(a.begin(), a.end());

        while(lo <= hi) {
            int mid = lo + (hi - lo) / 2;
            if(check(mid, n, a, k)) {
                hi = mid - 1;
            } else {
                lo = mid + 1;
            }
        }

        return lo;
    }
};