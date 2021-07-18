// https://www.scaler.com/problems/sum-of-xor-of-all-pairs/

/*
Given an array A of N integers. Find the sum of bitwise XOR all pairs of numbers in the array.
Since the answer can be large, return the remainder after the dividing the answer by 109+7.
*/

/*
For every bit, we can find the number of elements in the array with that bit set and the number of elements with that bit unset.
Let the number of elements with i-th bit set and unset be X and Y respectively.

Now the number of xor pairs with the i-th bit set is X*Y. 
So the total contribution by the i-th bit to the sum of xor
of all pairs will be (X * Y) * (1 << i).
*/

int Solution::solve(vector<int> &A) {
    const int mod = 1e9 + 7;    
    int n = A.size();
    long long ans = 0;
    for(int j = 0; j < 32; j++){
        long long zero = 0, one = 0, temp;
    
        //  Count of zeros and ones for each bit
        for(int i = 0; i < n; i++){
            if ((A[i] & (1 << j)) == 0)
                zero++;
            else
                one++;
        }
         
        // calculating individual bit sum
        temp = zero * one * (1 << j);
        ans = (ans + temp) % mod;
    }
    return ans;
}
