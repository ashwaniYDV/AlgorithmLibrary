// https://leetcode.com/problems/jump-game/
// https://leetcode.com/problems/jump-game-ii/
// https://leetcode.com/problems/jump-game-iii/
// https://leetcode.com/problems/jump-game-iv/



/*
Jump game I:
You are given an integer array nums. You are initially positioned at the array's first index, 
and each element in the array represents your maximum jump length at that position.
Return true if you can reach the last index, or false otherwise.
*/

class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n = nums.size();
        int maxReach = 0;
        
        for(int i = 0; i < n; i++) {
            if(i > maxReach) {
                return false;
            }
            maxReach = max(maxReach, i + nums[i]);
        }
        return true;
    }
};














// Jump game II
/*
Given an array of non-negative integers nums, you are initially positioned at the first index of the array.
Each element in the array represents your maximum jump length at that position.
Your goal is to reach the last index in the minimum number of jumps.
You can assume that you can always reach the last index.
*/

// Method 1: Time = O(n^2), Space = O(n)
class Solution {
public:
    int INF = 1e9;
    
    int jump(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n, INF);
        dp[0] = 0;
        for(int i = 0; i < n; i++) {
            for(int j = 1; j <= nums[i]; j++) {
                if(i + j >= n) break;
                dp[i + j] = min(dp[i + j], dp[i] + 1);
            }
        }
        return dp[n-1];
    }
};

// Method 2: Time = O(n^2), Space = O(n)
class Solution {
public:
    int INF = 1e9;
    int n;
    
    int go(int pos, vector<int>& jump, vector<int>& dp) {
        if(pos == n - 1) {
            return 0;
        }
        if(pos >= n || jump[pos] == 0) {
            return INF;
        }
        
        if(dp[pos] != -1) return dp[pos];

        int res = INF;
        for(int i = 1; i <= jump[pos]; i++) {
            res = min(res, 1 + go(pos + i, jump, dp));
        }

        return dp[pos] = res;
    }
    
    int jump(vector<int>& nums) {
        n = nums.size();
        vector<int> dp(n+5, -1);
        return go(0, nums, dp);
    }
};




// Method 3: Time = O(n), Space = O(1)
// https://youtu.be/a9r98S-pDvk

class Solution {
public:
    int jump(vector<int>& nums) {
        int n = nums.size();
        int jumps = 0, curReach = 0, maxReach = 0;

        /*
        We are taking jump from 0th index to the range maxReach
        
        curReach = we can take jump from particular index
        maxReach = we cango up to maximum
        jumps = to count no. of jumps
        */

        // NOTE: < n-1
        for (int i = 0; i < n - 1; i++) {
            maxReach = max(maxReach, i + nums[i]);
            // we have to take jump now because our currjump now ends
            if (i == curReach) {
                jumps++;
                curReach = maxReach;
            }
            if (curReach >= n - 1) {
                break;
            }
        }

        if (curReach < n - 1) return -1;
        return jumps;
    }
};



















/*
Jump game III:
Given an array of non-negative integers arr, you are initially positioned at start index of the array. 
When you are at index i, you can jump to i + arr[i] or i - arr[i], check if you can reach to any index with value 0.
Notice that you can not jump outside of the array at any time.
*/

class Solution {
public:
    bool dfs(vector<int>& arr, int i) {
        if (i < 0 || i >= arr.size() || arr[i] < 0) return false;
        if (arr[i] == 0) return true;
        
        // mark visited by making negative
        arr[i] = -arr[i];
        
        return dfs(arr, i + arr[i]) || dfs(arr, i - arr[i]);
    }
    
    bool canReach(vector<int>& arr, int start) {
        return dfs(arr, start);
    }
};
















/*
Jump game IV:

Given an array of integers arr, you are initially positioned at the first index of the array.

In one step you can jump from index i to index:
a) i + 1 where: i + 1 < arr.length.
b) i - 1 where: i - 1 >= 0.
c) j where: arr[i] == arr[j] and i != j.

Return the minimum number of steps to reach the last index of the array.
Notice that you can not jump outside of the array at any time.
*/

// Method 1
class Solution {
public:
    int minJumps(vector<int>& arr) {
        int n = arr.size();
        unordered_map<int, set<int>> neighbours;
        
        for(int i = 0; i < n; i++) {
            neighbours[arr[i]].insert(i);
        }

        queue<pair<int, int>> q;
        q.push({0, 0});
        
        vector<int> vis(n);
        vis[0] = 1;
        
        while(!q.empty()) {
            auto it = q.front();
            q.pop();
            int u = it.first, lvl = it.second;
            
            if(u == n - 1) return lvl;
            
            if(u - 1 >= 0 && !vis[u - 1]) {
                q.push({u - 1, lvl + 1});
                vis[u - 1] = 1;
            }
            if(u + 1 < n && !vis[u + 1]) {
                q.push({u + 1, lvl + 1});
                vis[u + 1] = 1;
            }
            
            for(int i: neighbours[arr[u]]) {
                if(i != u && !vis[i]) {
                    q.push({i, lvl + 1});
                    vis[i] = 1;
                    neighbours[arr[u]].erase(i);
                }
            }
        }
        
        return -1;
    }
};



// Method 2
class Solution {
public:
    int minJumps(vector<int>& arr) {
        int n = arr.size();
        unordered_map<int, vector<int>> neighbours;
        
        for(int i = 0; i < n; i++) {
            neighbours[arr[i]].push_back(i);
        }

        queue<pair<int, int>> q;
        q.push({0, 0});
        
        vector<int> vis(n);
        vis[0] = 1;
        
        while(!q.empty()) {
            auto it = q.front();
            q.pop();
            int u = it.first, lvl = it.second;
            
            if(u == n - 1) return lvl;
            
            if(u - 1 >= 0 && !vis[u - 1]) {
                q.push({u - 1, lvl + 1});
                vis[u - 1] = 1;
            }
            if(u + 1 < n && !vis[u + 1]) {
                q.push({u + 1, lvl + 1});
                vis[u + 1] = 1;
            }
            
            for(int i: neighbours[arr[u]]) {
                if(i != u && !vis[i]) {
                    q.push({i, lvl + 1});
                    vis[i] = 1;
                }
            }
            
            // remove for next iterations since already visited
            neighbours[arr[u]].clear();
        }
        
        return -1;
    }
};



// Method 3
class Solution {
public:
    int minJumps(vector<int>& arr) {
        int n = arr.size();
        unordered_map<int, vector<int>> neighbours;
        
        for(int i = 0; i < n; i++) {
            neighbours[arr[i]].push_back(i);
        }

        queue<pair<int, int>> q;
        q.push({0, 0});
        
        vector<int> vis(n);
        vis[0] = 1;
        int level = 0;
        
        while(!q.empty()) {
            int sz = q.size();
            while(sz--) {
                auto it = q.front();
                q.pop();
                int u = it.first, lvl = it.second;

                if(u == n - 1) return lvl;

                if(u - 1 >= 0 && !vis[u - 1]) {
                    q.push({u - 1, lvl + 1});
                    vis[u - 1] = 1;
                }
                if(u + 1 < n && !vis[u + 1]) {
                    q.push({u + 1, lvl + 1});
                    vis[u + 1] = 1;
                }

                for(int i: neighbours[arr[u]]) {
                    if(i != u && !vis[i]) {
                        q.push({i, lvl + 1});
                        vis[i] = 1;
                    }
                }

                // remove for next iterations since already visited
                neighbours[arr[u]].clear();
            }
            
            level++;
        }
        
        return -1;
    }
};
