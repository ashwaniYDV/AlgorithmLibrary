// https://leetcode.com/problems/maximum-subarray-sum-with-one-deletion/

/*
Given an array of integers, return the maximum sum for a non-empty subarray (contiguous elements) with at most one element deletion. 
In other words, you want to choose a subarray and optionally delete one element from it 
so that there is still at least one element left and the sum of the remaining elements is maximum possible.
Note that the subarray needs to be non-empty after deleting one element.

Input: arr = [1,-2,0,3]
Output: 4
Explanation: Because we can choose [1, -2, 0, 3] and drop -2, thus the subarray [1, 0, 3] becomes the maximum value.

Input: arr = [1,-2,-2,3]
Output: 3
Explanation: We just choose [3] and it's the maximum sum.

Constraints:
1 <= arr.length <= 10^5
-10^4 <= arr[i] <= 10^4
*/


// Method 1
/*
maxEndHere[i] is going to store maximum sum till index i including a[i] (i.e. a[i] is the ending index of subarray)
maxStartHere[i] is going to store maximum sum starting from index i including a[i] (i.e. a[i] is the starting index of subarray)
*/
class Solution {
public:
    int maximumSum(vector<int>& a) {
        int n = a.size();
        vector<int> maxEndHere(n), maxStartHere(n);

        int cur = 0;
        for (int i = 0; i < n; i++) {
            cur = max(a[i], cur + a[i]);
            maxEndHere[i] = cur;
        }
        cur = 0;
        for (int i = n - 1; i >= 0; i--) {
            cur = max(a[i], cur + a[i]);
            maxStartHere[i] = cur;
        }

        int res = INT_MIN;
        for (int i = 0; i < n; i++) {
            res = max({res, maxEndHere[i], maxStartHere[i]});
            if (i > 0 && i < n - 1) {
                res = max(res, maxEndHere[i - 1] + maxStartHere[i + 1]);
            }
        }
        return res;
    }
};

class Solution {
public:
    int maximumSum(vector<int>& a) {
        int n = a.size();
        vector<int> prefDP(n), sufDP(n);

        int cur = 0;
        for(int i = 0; i < n; i++) {
            cur = max(a[i], cur + a[i]);
            prefDP[i] = cur;
        }

        cur = 0;
        for(int i = n-1; i >= 0; i--) {
            cur = max(a[i], cur + a[i]);
            sufDP[i] = cur;
        }
        
        int res = INT_MIN;
        for(int i = 0; i < n; i++) {
            res = max({res, prefDP[i], sufDP[i]});
            if(i > 0 && i < n-1) {
                res = max(res, prefDP[i-1] + sufDP[i+1]);
            }
        }
        return res;
    }
};




// Space = O(1)
class Solution {
public:
    int maximumSum(vector<int>& arr) {
        int n = arr.size();
        int oneDelete = 0, noDelete = arr[0], res = arr[0];
        
        for(int i = 1; i < n; i++) {
            oneDelete = max(oneDelete + arr[i], noDelete);
            noDelete = max(noDelete + arr[i], arr[i]);
            res = max({res, noDelete, oneDelete});
        }
        return res;
    }
};