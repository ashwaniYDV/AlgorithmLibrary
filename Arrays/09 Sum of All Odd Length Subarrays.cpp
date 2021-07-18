// https://leetcode.com/problems/sum-of-all-odd-length-subarrays/

/*
Consider the contribution of A[i]

Consider the subarray that contains A[i],
we can take 0,1,2..,i elements on the left, from A[0] to A[i],
we have i + 1 choices.

we can take 0,1,2..,n-1-i elements on the right, from A[i] to A[n-1],
we have n - i choices.

In total, there are k = (i + 1) * (n - i) subarrays, that contains A[i].
And there are (k + 1) / 2 subarrays with odd length, that contains A[i].
And there are k / 2 subarrays with even length, that contains A[i].

A[i] will be counted ((i + 1) * (n - i) + 1) / 2 times for our question.
*/


class Solution {
public:
    int sumOddLengthSubarrays(vector<int>& arr) {
        int n = arr.size();
        int sum = 0;

        for (int i = 0; i < n; i++) {
            int left = i + 1;
            int right = n - i;
            int total = left * right;
            int odd = (total + 1) / 2;
            sum += odd * arr[i];
        }

        return sum;
    }
};
