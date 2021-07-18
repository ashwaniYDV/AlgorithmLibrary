// https://www.scaler.com/problems/subarray-or/

/*
Given an array of integers A of size N.
Value of a subarray is defined as BITWISE OR of all elements in it.
Return the sum of Value of all subarrays of A % 109 + 7.

Problem Constraints
1 <= N <= 10^5
1 <= A[i] <= 10^8


Input 1:
A = [1, 2, 3, 4, 5]
Output 1:
71
Explanation 1:
 Value([1]) = 1
 Value([1, 2]) = 3
 Value([1, 2, 3]) = 3
 Value([1, 2, 3, 4]) = 7
 Value([1, 2, 3, 4, 5]) = 7
 Value([2]) = 2
 Value([2, 3]) = 3
 Value([2, 3, 4]) = 7
 Value([2, 3, 4, 5]) = 7
 Value([3]) = 3
 Value([3, 4]) = 7
 Value([3, 4, 5]) = 7
 Value([4]) = 4
 Value([4, 5]) = 5
 Value([5]) = 5
Sum of all these values = 71


Input 2:
A = [7, 8, 9, 10]
Output 2:
110
*/


/*
Hint:
Think in term of a single bit of the number. If we find the number of times that bit will contribite in the answer. 

See scaler video editorial from Scaler TA account.
*/




#define ll long long
int Solution::solve(vector < int > & A) {
    int n = A.size();
    vector<int> idx(50, 0);

    ll res = 0;

    for (int i = 1; i <= n; ++i) {
        ll num = A[i - 1];
        for (int j = 0; j <= 31; ++j) {
            ll pow = 1L << j;
            //if jth bit is set
            if (num & pow) {
                // add its contribution in ans for all subarrays ending at index i
                res += i * pow;
                // store the index for next elements
                idx[j] = i;
            }
            // if jth bit is not set
            else {
                if (idx[j]) {
                    // add its contribution in ans for all subarrays ending at index i
                    // using the information of last element having jth bit set
                    res += idx[j] * pow;
                }
            }
        }
    }
    return res % 1000000007;
}
