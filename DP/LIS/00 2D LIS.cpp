/*
There is an array A of n integers. 
Your task is to chose as many integers from A as possible so that,
when they are put in ascending order, all of the differences between all pairs of consecutinve integers are equal.
What is the max no of integers that can be chosen.

Eg:
A = [4, 3, 5, 1, 4, 4]
you could chose (1, 3, 5) with diff = 2
or
you could chose (4, 4, 4) with diff = 0
in both case res = 2

Constraints:
2 <= N <= 50
1 <= A[i] <= 100
*/

int fun(vector<int>& nums) {
    int n = nums.size();
    if(n <= 2) return n;

    sort(nums.begin(), nums.end());
    
    vector<vector<int>> dp(n, vector<int> (100, 1));
    int ans = 0;
    
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < i; j++) {
            int d = nums[i] - nums[j];
            dp[i][d] = max(dp[i][d], dp[j][d] + 1);
            ans = max(ans, dp[i][d]);
        }
    }
    return ans;
}
