// https://www.scaler.com/problems/balance-array/

/*
Given an integer array A of size N. You need to count the number of special elements in the given array.
A element is special if removal of that element make the array balanced.
Array will be balanced if sum of even index element equal to sum of odd index element.
*/


/*
Maintain PrefixSum and SuffixSum for odd and even index seperately.
Let consider the following variable:
leftOdd[i] : Denote the prefixSum of element on odd index till i-1.
leftEven[i] : Denote the prefixSum of element on even index till i-1.
rightOdd[i] : Denote the SuffixSum of element of odd index till i+1.
rightEven[i] : Denote the SuffixSum of element of even index till i+1.

Now, check if the ith element is the special or not.
If leftOdd[i] + rightEven[i] == leftEven[i] + rightOdd[i], then ith element is special, so we increase the count.
*/


int Solution::solve(vector<int> &A) {
    int n = A.size();
    int odd = 0, even = 0;
    int leftOdd[n], rightOdd[n];
    int leftEven[n], rightEven[n];
    for(int i = 0;i < n; i++){
        leftOdd[i] = odd;
        leftEven[i] = even;
        if(i%2 == 0)
            even += A[i];
        else
            odd += A[i];
    }
    odd = 0;
    even = 0;
    for(int i = n-1; i >= 0; i--){
        rightOdd[i] = odd;
        rightEven[i] = even;
        if(i%2 == 0)
            even += A[i];
        else
            odd += A[i];
    }
    int ans = 0;
    for(int i = 0; i < n; i++){
        if(leftOdd[i] + rightEven[i] == leftEven[i] + rightOdd[i]){
            ans++;
        }
    }
    return ans;
}
