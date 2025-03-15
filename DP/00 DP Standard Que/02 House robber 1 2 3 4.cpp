// https://leetcode.com/problems/house-robber/
// https://youtu.be/GrMBfJNk_NY?si=-qvs6C_PJ-TOVa0l

/*
You are a professional robber planning to rob houses along a street. 
Each house has a certain amount of money stashed.
Adjacent houses have security systems connected and it will automatically contact police if two adjacent houses were broken in same night.
Given an integer array nums representing the amount of money of each house, return max amount of money you can rob tonight without alerting police.
*/


// top down
class Solution {
public:
    int f(int i, vector<int>& nums, vector<int>& dp) {
        if(i < 0) return 0;

        if(dp[i] != -1) return dp[i];

        int pick = nums[i] + f(i - 2, nums, dp);
        int notPick = f(i - 1, nums, dp);
        
        return dp[i] = max(pick, notPick);
    }
    int rob(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n + 1, -1);
        return f(n - 1, nums, dp);
    }
};


// bottom up
class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n + 1, 0);

        dp[0] = nums[0];

        for(int i = 1; i < n; i++) {
            int pick = nums[i] + (i - 2 >= 0 ? dp[i - 2] : 0);
            int notPick = dp[i - 1];
            dp[i] = max(pick, notPick);
        }

        return dp[n-1];
    }
};


// space optimized
class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();

        int prev1 = nums[0];
        int prev2 = 0;

        for(int i = 1; i < n; i++) {
            int pick = nums[i] + prev2;
            int notPick = prev1;
            
            int cur = max(pick, notPick);

            prev2 = prev1;
            prev1 = cur;
        }

        return prev1;
    }
};








// https://leetcode.com/problems/house-robber-ii/
// https://youtu.be/3WaxQMELSkw?si=pBnihXAfO_UQYJVq

/*
You are a professional robber planning to rob houses along a street. 
Each house has a certain amount of money stashed.
All houses at this place are arranged in a circle.
That means the first house is the neighbor of the last one. 
Adjacent houses have security systems connected and it will automatically contact police if two adjacent houses were broken in same night.
Given an integer array nums representing the amount of money of each house, return max amount of money you can rob tonight without alerting police.

Input: nums = [2,3,2]
Output: 3
Explanation: You cannot rob house 1 (money = 2) and then rob house 3 (money = 2), 
because they are adjacent houses.
*/
    
    
// Method 1
class Solution {
public:
    int f(int i, int isLastEleTaken, vector<int>& nums, vector<vector<int>>& dp) {
        if(i < 0) return 0;

        if(dp[i][isLastEleTaken] != -1) return dp[i][isLastEleTaken];

        int pick = 0;
        // taking the last element
        if(i == nums.size() - 1) {
            pick = nums[i] + f(i - 2, 1, nums, dp);
        } else if(i != 0) {
            pick = nums[i] + f(i - 2, isLastEleTaken, nums, dp);
        }

        // if last element is not taken then only i can take first element
        if(i == 0 && !isLastEleTaken) {
            pick = nums[i];
        }

        int notPick = f(i - 1, isLastEleTaken, nums, dp);
        
        return dp[i][isLastEleTaken] = max(pick, notPick);
    }
    int rob(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> dp(n + 1, vector<int>(2, -1));
        return f(n - 1, 0, nums, dp);
    }
};



// Method 2: Space optimized solution
/*
Since we cannot rob both first and last house, 
We will create two temp arrays and call same function used in "house robber 1" problem
and return max answer of them.

Array 1 will not contain first house.
Array 2 will not contain last house.
*/
class Solution {
public:
    int maxSumOfNonAdjEle(vector<int>& nums) {
        int n = nums.size();

        int prev1 = nums[0];
        int prev2 = 0;

        for(int i = 1; i < n; i++) {
            int pick = nums[i] + prev2;
            int notPick = prev1;
            
            int cur = max(pick, notPick);

            prev2 = prev1;
            prev1 = cur;
        }

        return prev1;
    }

    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n == 1) return nums[0];

        vector<int> temp1; // contains nums[1, , , n-1]
        vector<int> temp2; // contains nums[0, , , n-2]

        for(int i = 0; i < n; i++) {
            if(i != 0) temp1.push_back(nums[i]);
            if(i != n-1) temp2.push_back(nums[i]);
        }

        return max(maxSumOfNonAdjEle(temp1), maxSumOfNonAdjEle(temp2));
    }
};










// https://leetcode.com/problems/house-robber-iii/
/*
The thief has found himself a new place for his thievery again. 
There is only one entrance to this area, called root.
Besides the root, each house has one and only one parent house. 
After a tour, the smart thief realized that all houses in this place form a binary tree. 
It will automatically contact the police if two directly-linked houses were broken into on the same night.
Given the root of the binary tree, return the maximum amount of money the thief can rob without alerting the police.
*/

class Solution {
public:
    // {notPick, pick}
    pair<int, int> f(TreeNode* root) {
        if(!root) return {0, 0};

        int notPick = 0, pick = root->val;

        pair<int, int> left = f(root->left);
        notPick += max(left.first, left.second);
        pick += left.first;

        pair<int, int> right = f(root->right);
        notPick += max(right.first, right.second);
        pick += right.first;

        return {notPick, pick};
    }

    int rob(TreeNode* root) {
        auto it = f(root);
        return max(it.first, it.second);
    }
};






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