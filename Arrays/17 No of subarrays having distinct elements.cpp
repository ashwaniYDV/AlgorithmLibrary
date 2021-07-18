// https://www.scaler.com/problems/count-subarrays/

/*
Find the number of subarrays of A, that have unique elements.
Since the number of subarrays could be large, return value % 10^9 +7.


Problem Constraints
1 <= N <= 10^5
1 <= A[i] <= 10^6

Input 1:
A = [1, 1, 3]
Output 1:
4
Explanation 1:
Subarrays of A that have unique elements only:
[1], [1], [1, 3], [3]
 
Input 2:
A = [2, 1, 2]
Output 1:
5
Explanation 2:
Subarrays of A that have unique elements only:
[2], [1], [2, 1], [1, 2], [2]
*/



int Solution::solve(vector<int> &A) {
    long long mod = 1e9 + 7;
    long long l = 0, n = A.size();

    // create a map to store unique elements
    map <int, int> mp;
    long long res = 0;

    for (int r = 0; r < n; r++) {
        mp[A[r]]++;
        while (mp[A[r]] > 1) {
            mp[A[l]]--;
            l++;
        }

        int len = (r - l + 1);
        res = (res + len) % mod;
    }

    return res;
}
















// https://practice.geeksforgeeks.org/problems/sum-of-length3345/1

/*
Given an array. Calculate the sum of lengths of contiguous subarrays having all distinct elements.
*/

class Solution {
public:
    int sumoflength(int A[], int n) {
        int l = 0;

        // create a map to store unique elements
        unordered_map <int, int> mp;
        int res = 0;

        for (int r = 0; r < n; r++) {
            mp[A[r]]++;
            while (mp[A[r]] > 1) {
                mp[A[l]]--;
                l++;
            }

            int len = (r - l + 1);
            res += len * (len + 1) / 2;
        }

        return res;
    }
};
