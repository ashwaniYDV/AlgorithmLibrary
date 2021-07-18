// https://leetcode.com/problems/unique-binary-search-trees/

/*
Given an integer n, return the number of structurally unique BST's (binary search trees) which has exactly n nodes of unique values from 1 to n.
*/

// MEthod 1: Using Catalan numbers
class Solution {
    int catalan_Number(int n)
    {
        int catalan[n+1];
        catalan[0] = catalan[1] = 1;
        
        for(int i=2;i<=n;++i)
        {
            catalan[i] = 0;
            for(int j=0;j<i;++j)
                catalan[i] += catalan[j]*catalan[i-j-1];
        }
        return catalan[n];
    }
public:
    int numTrees(int n) {
        return catalan_Number(n);
    }
};



// MEthod 2: "Using Unique Binary Search Trees II" problem technique
class Solution {
public:
    int helper(int start, int end, vector<vector<int>>& dp) {
        if(start > end) {
            return 1;
        }
        
        if(dp[start][end] != -1) return dp[start][end];
        
        int res = 0;
      
        // making i as the root for each i from start to end
        for(int i = start; i <= end; i++) {
            int left = helper(start, i-1, dp);
            int right = helper(i+1, end, dp);
            
            res += left * right;
        }
        
        return dp[start][end] = res;
        
    }
    int numTrees(int n) {
        if(n == 0) return 0;
        
        vector<vector<int>> dp(n+1, vector<int>(n+1, -1));
        return helper(1, n, dp);
    }
};
