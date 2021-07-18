// https://practice.geeksforgeeks.org/problems/rod-cutting0840/1
// https://www.techiedelight.com/rod-cutting/

/*
Given a rod of length n and a list of rod prices of length i, where 1 <= i <= n, 
find the optimal way to cut the rod into smaller rods to maximize profit.
*/

/*
This problem is very similar to the Unbounded Knapsack Problem, where there are multiple occurrences of the same item. Here the pieces of the rod.

An analogy between Unbounded Knapsack and the Rod Cutting Problem:

______________________________________________________________________________________________________
Unbounded Knapsack Problem                    |       Rod Cutting Problem
______________________________________________________________________________________________________
Size of array (n)                             |       Length of rod (n)
Value of the item (value[])                   |       Price of the pieces of rod (price[])
Weight array (weitht[])                       |       Length of array (length[])
Max knapsack capacity (W)                     |       Length of main rod (n == mxLength)
______________________________________________________________________________________________________
*/


// Method 1: Unbounded Knapsack concept O(n*m) memory
class Solution{
  public:
    int cutRod(int price[], int n) {
        vector<int> length(n);
        for(int i = 0; i < n; i++) length[i] = i + 1;
    
        int mxLength = n;
    
        int dp[n + 1][mxLength + 1];
    
        for(int i = 0; i <= n; i++) {
            for(int j = 0; j <= mxLength; j++) {
                if(i == 0 || j == 0) {
                    dp[i][j] = 0;
                } else if(j < length[i - 1]) {
                    dp[i][j] = dp[i - 1][j];
                } else {
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - length[i - 1]] + price[i - 1]);
                }
            }
        }
        return dp[n][mxLength];
    }
};




// Method 2: Unbounded Knapsack concept O(m) memory
class Solution{
  public:
    int cutRod(int price[], int n) {
        int length[n];
        for(int i = 0; i < n; i++) length[i] = i + 1;
        
        int mxLength = n;
        int dp[mxLength + 1] = {0};
        
        for(int i = 0; i < n; i++) {
            for(int j = 0; j <= mxLength; j++) {
                if(j >= length[i]) {
                    dp[j] = max(dp[j], dp[j - length[i]] + price[i]);
                }
            }
        }
        return dp[mxLength];
    }
};












// Method 3: O(m) memory
class Solution {
public:
    int cutRod(int price[], int n) {
        // dp[i] denotes the max value of rod length i, so answer = dp[n]
        vector<int> dp(n + 1, 0);

        dp[0] = 0; // when no element is included

        for (int i = 1; i <= n; i++) {
            for (int j = 0; j < i; j++) {
                dp[i] = max(dp[i], dp[j] + price[i - j - 1]);
            }
        }

        return dp[n];
    }
};






// Method 4: Memoised
class Solution{
  public:
    int go(int pos, int n, int price[], vector<int>& dp) {
    	if(pos == n) return 0;
    	if(pos > n) return INT_MIN;
    	
    	if(dp[pos] != -1) return dp[pos];
    
    	int res = 0;
    	for(int i = pos; i < n; i++) {
    		res = max(res, price[i - pos] + go(i + 1, n, price, dp));
    	}
    
    	return dp[pos] = res;
    }
    int cutRod(int price[], int n) {
        vector<int> dp(10000, -1);
        return go(0, n, price, dp);
    }
};





#include <iostream>
#include <string>
#include <climits>
using namespace std;
 
// Function to find the best way to cut a rod of length `n`
// where the rod of length `i` has a cost `price[i-1]`
int rodCut(int price[], int n) {
    // base case
    if (n == 0) {
        return 0;
    }
 
    int maxValue = INT_MIN;
 
    // one by one, partition the given rod of length `n` into two parts
    // of length (1, n-1), (2, n-2), (3, n-3), … ,(n-1, 1), (n, 0)
    // and take maximum
    for (int i = 1; i <= n; i++) {
        // rod of length `i` has a cost `price[i-1]`
        int cost = price[i - 1] + rodCut(price, n - i);
 
        if (cost > maxValue) {
            maxValue = cost;
        }
    }
 
    return maxValue;
}
 
int main() {
    int price[] = { 1, 5, 8, 9, 10, 17, 17, 20 };
 
    // rod length
    int n = 4;
 
    cout << "Profit is " << rodCut(price, n);
 
    return 0;
}
