// https://leetcode.com/discuss/interview-question/613310/microsoft-rod-cutting
// https://www.geeksforgeeks.org/cutting-a-rod-dp-13/
// https://practice.geeksforgeeks.org/problems/rod-cutting0840/1

// Method 1
int go(int pos, int n, int price[], vector<int>& dp) {
	if(pos == n) return 0;
	if(pos > n) return INT_MIN;
	
	if(dp[pos] != -1) return dp[pos];

	int res = 0;
	for(int i = pos; i < n; i++) {
		res = max(res, price[i - pos] + go(i+1, n, price, dp));
	}

	return dp[pos] = res;
}
int cutRod(int price[], int n) {
    vector<int> dp(10000, -1);
    return go(0, n, price, dp);
}




// Method 2
int cutRod(int price[], int n) {
    vector<int> dp(n+1, 0);
    
    dp[0] = 0; // when no element is included
    dp[1] = price[0]; // when only first element is included
    
    for(int i = 2; i <= n; i++) {
        for(int j = 0; j < i; j++) {
            dp[i] = max(dp[i], dp[j] + price[i - j - 1]);
        }
    }
    
    return dp[n];
}
