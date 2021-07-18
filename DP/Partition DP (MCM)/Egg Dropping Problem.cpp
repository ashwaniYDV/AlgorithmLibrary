// https://leetcode.com/problems/super-egg-drop/
// https://www.geeksforgeeks.org/egg-dropping-puzzle-dp-11/
// https://youtu.be/UvksR0hR9nA

/*
Abe suno yeh egg dropping problem ke variations me chutiya smghta tha lekin ek baar dekh lo bc sb variation alag trike se solve hota

N floor 1egg (greedy)
N floor 2 egg (greedy)
N floor k egg (dp)
N floor infinite egg (binary search)
Infinite floor infinite egg (binary search)
*/

/*
You are given k identical eggs and you have access to a building with n floors labeled from  1 to n.
You know that there exists a floor f where 0 <= f <= n such that any egg dropped at a floor higher than f will break, 
and any egg dropped at or below floor f will not break.
Each move, you may take an unbroken egg and drop it from any floor x (where 1 <= x <= n). 
If the egg breaks, you can no longer use it. However, if the egg does not break, you may reuse it in future moves.
Return the minimum number of moves that you need to determine with certainty what the value of f is.

Constraints:
1 <= k <= 100
1 <= n <= 10^4
*/




/*
The basic idea is, we have to find the minimum number of attempts to find the threshold Floor, 
that means, above that floor the egg will break and below or equal to that floor the egg will not break.

So, we have two choices
1. Egg will break
2. Egg will not break

-> Case 1: if the egg will break from a particular floor then we have to go below that floor
-> Case 2: if the egg will not break from a particular floor then we have to go above to find the threshold floor

Base Conditions:
1. It is given that egg the will not be 0 so no check for this in code
2. If the egg will be 1 i.e. k = 1, So we need at minimum n moves to determine what the value of floor is i.e n attempts.
3. If the n is 0 then no floor 0 attempt.
4. If the n is 1 then only 1 attempt.

Why Binary Search?
Notice that for the same K when N goes up, dp[K][N] goes up.
Then for int left = go(K - 1, i - 1, dp); int right = go(K, N - i, dp); when i goes up, left goes up and right goes down.
We can use Binary Search here to get the minimum {1 + max(left, right)}, when left and right are as close as possible.
We come to O(K*N*logN) solution.
*/






// TLE Solution
class Solution {
public:
    int superEggDrop(int k, int n) {
        int eggs = k, floors = n;
        int dp[eggs + 1][floors + 1];
        memset(dp, 0, sizeof dp);

        // i = egg, j = floor
        for (int i = 1; i <= eggs; i++) {
            for (int j = 1; j <= floors; j++) {
                // only 1 egg
                if (i == 1) {
                    dp[i][j] = j;
                }
                // only 1 floor
                else if (j == 1) {
                    dp[i][j] = 1;
                } else {
                    int mn = INT_MAX;
                    int l = 0, r = j - 1;
                    while(l < j && r >= 0) {
                        // egg breaks
                        int v2 = dp[i - 1][l];
                        // egg survives
                        int v1 = dp[i][r];
                        mn = min(mn, max(v1, v2));
                        l++; r--;
                    }
                    dp[i][j] = mn + 1;
                }
            }
        }

        return dp[eggs][floors];
    }
};


// AC Solution
class Solution {
public:
    int superEggDrop(int k, int n) {
        int eggs = k, floors = n;
        int dp[eggs + 1][floors + 1];
        memset(dp, 0, sizeof dp);

        // i = egg, j = floor
        for (int i = 1; i <= eggs; i++) {
            for (int j = 1; j <= floors; j++) {
                // only 1 egg
                if (i == 1) {
                    dp[i][j] = j;
                }
                // only 1 floor
                else if (j == 1) {
                    dp[i][j] = 1;
                } else {
                    int l = 1, r = j, temp = 0, ans = INT_MAX;
                    while(l < r) {
                        int mid = (l + r) / 2;
                        int left = dp[i - 1][mid - 1];
                        int right = dp[i][j - mid];
                        temp = 1 + max(left, right);
                        if(left < right) 
                            l = mid + 1;
                        else 
                            r = mid;
                        ans = min(ans, temp);
                    }
                    dp[i][j] = ans;
                }
            }
        }

        return dp[eggs][floors];
    }
};


class Solution {
public:
    int superEggDrop(int k, int n) {
        int eggs = k, floors = n;
        int dp[eggs + 1][floors + 1];
        memset(dp, 0, sizeof dp);

        // i = egg, j = floor
        for (int i = 1; i <= eggs; i++) {
            for (int j = 1; j <= floors; j++) {
                // only 1 egg
                if (i == 1) {
                    dp[i][j] = j;
                }
                // only 1 floor
                else if (j == 1) {
                    dp[i][j] = 1;
                } else {
                    int l = 1, r = j, temp = 0, ans = INT_MAX;
                    while(l <= r) {
                        int mid = (l + r) / 2;
                        int left = dp[i - 1][mid - 1];
                        int right = dp[i][j - mid];
                        temp = 1 + max(left, right);
                        if(left < right) l = mid + 1;
                        else r = mid - 1;
                        ans = min(ans, temp);
                    }
                    dp[i][j] = ans;
                }
            }
        }

        return dp[eggs][floors];
    }
};























// ❌ This Solution will give TLE
class Solution {
public:
    int superEggDrop(int k, int n) {
        int eggs = k, floors = n;
        
        int dp[eggs+1][floors+1];
        for(int i = 0; i <= floors; i++) dp[0][i] = INT_MAX;
        for(int i = 0; i <= floors; i++) dp[1][i] = i;
        for(int i = 0; i <= eggs; i++) dp[i][0] = 0;
        for(int i = 0; i <= eggs; i++) dp[i][1] = 1;
        
        for(int i = 2; i <= eggs; i++) {
            for(int j = 2; j <= floors; j++) {
                int curr_ans = INT_MAX;
                int l = 0, r = j-1;
                while(l < j && r >= 0){
                    curr_ans = min(curr_ans, max(dp[i-1][l], dp[i][r]));
                    l++; r--;
                }
                dp[i][j] = curr_ans + 1;
            }
        }
        return dp[eggs][floors];
    }
};


// ✅ Using Binary Search
class Solution {
public:
    int superEggDrop(int k, int n) {
        int eggs = k, floors = n;
        
        int dp[eggs+1][floors+1];
        for(int i = 0; i <= floors; i++) dp[0][i] = INT_MAX;
        for(int i = 0; i <= floors; i++) dp[1][i] = i;
        for(int i = 0; i <= eggs; i++) dp[i][0] = 0;
        for(int i = 0; i <= eggs; i++) dp[i][1] = 1;
        
        for(int i = 2; i <= eggs; i++) {
            for(int j = 2; j <= floors; j++) {
                int l = 1, r = j, temp = 0, ans = INT_MAX;
                while(l < r) {
                    int mid = (l + r) / 2;
                    int left = dp[i - 1][mid - 1];
                    int right = dp[i][j - mid];
                    temp = 1 + max(left, right);
                    if(left < right) 
                        l = mid + 1;
                    else 
                        r = mid;
                    ans = min(ans, temp);
                }
                dp[i][j] = ans;
            }
        }
        return dp[eggs][floors];
    }
};

class Solution {
public:
    int superEggDrop(int k, int n) {
        int eggs = k, floors = n;
        
        int dp[eggs+1][floors+1];
        for(int i = 0; i <= floors; i++) dp[0][i] = INT_MAX;
        for(int i = 0; i <= floors; i++) dp[1][i] = i;
        for(int i = 0; i <= eggs; i++) dp[i][0] = 0;
        for(int i = 0; i <= eggs; i++) dp[i][1] = 1;
        
        for(int i = 2; i <= eggs; i++) {
            for(int j = 2; j <= floors; j++) {
                int l = 1, r = j, temp = 0, ans = INT_MAX;
                while(l <= r) {
                    int mid = (l + r) / 2;
                    int left = dp[i - 1][mid - 1];
                    int right = dp[i][j - mid];
                    temp = 1 + max(left, right);
                    if(left < right) l = mid + 1;
                    else r = mid - 1;
                    ans = min(ans, temp);
                }
                dp[i][j] = ans;
            }
        }
        return dp[eggs][floors];
    }
};




















// TLE top - down
class Solution {
public:
    int go(int eggs, int floors, vector<vector<int>>& dp){
        if(floors == 0 || floors == 1) return floors;
        if(eggs == 1) return floors;
        
        if(dp[eggs][floors] != -1) return dp[eggs][floors];
        
        int res = INT_MAX;
        
        for(int i = 1; i <= floors; i++) {
            /*
            Case 1: if the egg will break, 
                    No. of eggs will decrease and we have to down from that floor.
            Case 2: if the egg will not break, 
                    No. of eggs will not decrease and we have to go above form that floor.
            */
            int temp = 1 + max(go(eggs - 1, i - 1, dp), go(eggs, floors - i, dp));
            // best of the worst
            res = min(res, temp);
        }
        return dp[eggs][floors] = res;
    }
    
    int superEggDrop(int k, int n) {
        // k = eggs, n = floors
        vector<vector<int>> dp(k + 1, vector<int>(n + 1, -1));
        return go(k, n, dp);
    }
};




// AC top - down
class Solution {
public:
    int go(int eggs, int floors, vector<vector<int>>& dp){
        if(floors == 0 || floors == 1) return floors;
        if(eggs == 1) return floors;
        
        if(dp[eggs][floors] != -1) return dp[eggs][floors];
        
        int res = INT_MAX, low = 0, high = floors, temp = 0;
        while(low < high) {
            int mid = (low + high) / 2;
            
            /*
            Case 1: if the egg will break, 
                    No. of eggs will decrease and we have to down from that floor.
            Case 2: if the egg will not break, 
                    No. of eggs will not decrease and we have to go above form that floor.
            */
            
            int left = go(eggs - 1, mid - 1, dp);
            int right = go(eggs, floors - mid, dp);
            temp = 1 + max(left, right);
            
            // since we need more temp value in worst case, so need to go above
            if(left < right) {
                low = mid + 1;
            }
            // move to the downward
            else { 
                high = mid;
            }
    
            // best fo the worst
            res = min(res, temp);
        }
        
        return dp[eggs][floors] = res;
    }
    
    int superEggDrop(int k, int n) {
        // k = eggs, n = floors
        vector<vector<int>> dp(k + 1, vector<int>(n + 1, -1));
        return go(k, n, dp);
    }
};
