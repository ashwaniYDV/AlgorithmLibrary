/*
Given a non-negative integer x, return the square root of x rounded down to the nearest integer. 

Input: x = 8
Output: 2
Explanation: The square root of 8 is 2.82842..., and since we round it down to the nearest integer, 2 is returned.
*/

class Solution {
public:
    int mySqrt(int n) {
        int lo = 1, hi = n;
        while(lo <= hi) {
            long long mid = lo + (hi - lo) / 2;
            long long sqr = mid * mid;

            if(sqr == n) return mid;

            if(sqr < n) {
                lo = mid + 1;
            } else {
                hi = mid - 1;
            }
        }

        // binary search ends when (lo > hi) and hi is the integer value of square root.
        return hi;
    }
};