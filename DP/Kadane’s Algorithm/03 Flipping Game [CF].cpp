// https://www.scaler.com/problems/flip/
// https://codeforces.com/problemset/problem/327/A

/*
You are given a binary string A consisting of characters A1, A2, ..., AN. 
In a single operation, you can choose two indices, L and R (1 ≤ L ≤ R ≤ N) 
and flip the characters AL, AL+1, ..., AR. 

Your aim is to perform ATMOST one operation such that in final string number of 1s is maximized.
If you don't want to perform the operation, return an empty array. 
Else, return an array consisting of two elements denoting L and R. 
If there are multiple solutions, return the lexicographically smallest pair of L and R.
*/


/*
Note the net change in the number of 1s in string S when we flip bits of string S.
Say it has A 0s and B 1s. Eventually, there are B 0s and A 1s.
So, the number of 1s increased by A - B. 
We want to choose a subarray that maximizes this. 
Note that if we change (1s to -1) and (0s to 1s), the sum of values will give us A - B. 
Then, we have to find a subarray with the maximum sum, which can be done via Kadane’s Algorithm.
*/

vector < int > Solution::flip(string A) {
    int n = A.length();
    
    //build new array of 1s and -1s
    vector < int > ar(n);
    for (int i = 0; i < n; i++) {
        if (A[i] == '1')
            ar[i] = -1;
        else
            ar[i] = 1;
    }
    
    //pair storing the answer
    pair < int, int > ans = make_pair(INT_MAX, INT_MAX);
    
    int maxSoFar = 0, maxEndingHere = 0;
    int beg = 0;
    for (int i = 0; i < n; i++) {
        maxEndingHere += ar[i];
        
        if (maxEndingHere < 0) {
            beg = i + 1;
            maxEndingHere = 0;
        }

        if (maxSoFar < maxEndingHere) {
            maxSoFar = maxEndingHere;
            ans.first = beg;
            ans.second = i;
        }
    }
    
    //if no valid subarray found
    if (ans.first == INT_MAX) return vector<int>();
    return vector <int> { ans.first + 1, ans.second + 1};
}