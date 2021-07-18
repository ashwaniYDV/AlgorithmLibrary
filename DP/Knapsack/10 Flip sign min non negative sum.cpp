// https://www.scaler.com/problems/flip-array/

/*
Given an array A of positive elements, you have to flip the sign of some of its elements such that 
the resultant sum of the elements of array should be minimum non-negative (as close to zero as possible).
Return the minimum number of elements whose sign needs to be flipped such that the resultant sum is minimum non-negative.
*/

/*
Let the sum of all the given elements be S. This problem can be reduced to a Knapsack problem 
where we have to fill a Knapsack of capacity (S/2) as fully as possible and using the minimum no. of elements. 
We will fill the Knapsack with the given elements. Sign of all the elements which come into the knapsack will be flipped. 
As sum of all the elements in the Knapsack will be as close to S/2 as possible, 
we are indirectly calculating minimum non-negative sum of all the elements after flipping the sign. Give it a thought and code your way out!
*/


// dp[i][j] = optimal solution for filling a knapsack of capacity j using elements A[1,2,....,i]
// Optimal solution --> knapsack should be filled upto the capacity using least number of elements

struct node {
    int items;
    int weight;
} dp[105][10005];

int Solution::solve(const vector<int>& A) {
    int n = A.size();
    int sum = 0;
    for(int i = 0; i < n; i++) sum += A[i];
    
    //knapsack algorithm for capacity sum/2
    int temp = sum / 2;
    
    for(int i = 0; i <= n; i++) {
        for(int j = 0; j <= temp; j++) {
            if(i == 0 || j == 0) {
                dp[i][j] = {0, 0};
            } else {
                if(j < A[i-1]) {
                    dp[i][j] = dp[i-1][j];
                } else {
                    int prev_weight = dp[i - 1][j].weight;
                    int prev_items = dp[i - 1][j].items;
                    int curr_weight = dp[i - 1][j - A[i - 1]].weight + A[i - 1];
                    int curr_items = dp[i - 1][j - A[i - 1]].items + 1;
                    
                    if((curr_weight > prev_weight) || ((curr_weight == prev_weight) && (curr_items < prev_items))) {
                        dp[i][j] = {curr_items, curr_weight}; 
                    } else {
                        dp[i][j] = dp[i - 1][j];
                    }
                }
            }
        }
    }
    
    return dp[n][temp].items;
}
